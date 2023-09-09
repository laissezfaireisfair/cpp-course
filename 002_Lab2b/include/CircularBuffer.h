#pragma once

#include <cstdint>
#include <stdexcept>
#include <memory>

namespace collections {
using Byte = char;

template<class T>
class CircularBuffer {
 public:
  CircularBuffer() : body_(nullptr), begin_(0), size_(0), capacity_(0), mem_pool_(nullptr) {
  }

  explicit CircularBuffer(size_t const capacity) : CircularBuffer() {
    AllocBody(capacity);
  }

  CircularBuffer(size_t const size, T const &value) : CircularBuffer(size) {
    for (size_ = 0; size_ < size; ++size_)
      new (&body_[size_]) T(value);
  }

  CircularBuffer(CircularBuffer<T> const &other) : CircularBuffer(other.capacity_) {
    InitializeBodyFromOther(other);
  }

  CircularBuffer(CircularBuffer<T> &&other) = default;

  ~CircularBuffer() {
    Deinitialize();
  }

  size_t GetSize() const noexcept {
    return size_;
  }

  size_t GetCapacity() const noexcept {
    return capacity_;
  }

  bool IsEmpty() const noexcept {
    return size_ == 0;
  }

  T &At(size_t const place) {
    if (place >= capacity_)
      throw std::out_of_range("Try to reach elem outside of buffer");

    if (place >= size_)
      throw std::out_of_range("Try to reach non-initialized elem of buffer");

    return operator[](place);
  }

  T const &At(size_t const place) const {
    if (place >= capacity_)
      throw std::out_of_range("Try to reach elem outside of buffer");

    if (place >= size_)
      throw std::out_of_range("Try to reach non-initialized elem of buffer");

    return operator[](place);
  }

  T &operator[](size_t const place) {
    return body_[RealPlace(place)];
  }

  T const &operator[](size_t const place) const {
    return body_[RealPlace(place)];
  }

  T &GetFront() {
    return At(0);
  }

  T const &GetFront() const {
    return At(0);
  }

  T &GetBack() {
    if (IsEmpty())
      throw std::logic_error("Try to get last item from empty buffer");

    return At(size_ - 1);
  }

  T const &GetBack() const {
    return At(size_ - 1);
  }

  void PushBack(T const &elem) {
    if (IsFull())
      throw std::overflow_error("Pushing to full container");

    new(&body_[RealPlace(size_)]) T(elem);
    ++size_;
  }

  void PushBack(T &&elem) {
    if (IsFull())
      throw std::overflow_error("Pushing to full container");

    new(&body_[RealPlace(size_)]) T(std::forward<T>(elem));
    ++size_;
  }

  void PushFront(T const &elem) {
    if (IsFull())
      throw std::overflow_error("Pushing to IsFull container");

    auto const kPlaceNew = RealPlace(capacity_ - 1);
    new(&body_[kPlaceNew]) T(elem);
    begin_ = kPlaceNew;
    ++size_;
  }

  void PushFront(T &&elem) {
    if (IsFull())
      throw std::overflow_error("Pushing to IsFull container");

    auto const kPlaceNew = RealPlace(capacity_ - 1);
    new(&body_[kPlaceNew]) T(std::forward<T>(elem));
    begin_ = kPlaceNew;
    ++size_;
  }

  void PopFront() {
    if (IsEmpty())
      throw std::underflow_error("Try to pop empty container");

    At(0).~T();
    --size_;
    if (size_ == 0)
      begin_ = 0;
    else
      begin_ = RealPlace(begin_ + 1);
  }

  void PopBack() {
    if (IsEmpty())
      throw std::underflow_error("Try to pop empty container");

    At(size_ - 1).~T();
    --size_;
    if (size_ == 0)
      begin_ = 0;
  }

  void Clean() {
    for (; size_ > 0; --size_)
      GetBack().~T();

    begin_ = 0;
  }

  void RotateForward(size_t const distance) {
    if (!IsFull())
      throw std::logic_error("Try to rotate not full buffer");

    size_t positiver;
    for (positiver = 0; positiver + begin_ < distance; positiver += capacity_) {}

    begin_ = positiver + begin_ - distance;
  }

  void RotateBack(size_t const distance) {
    if (!IsFull())
      throw std::logic_error("Try to rotate not full buffer");

    begin_ = RealPlace(distance);
  }

  CircularBuffer<T> &operator=(CircularBuffer<T> &&other) = default;

  CircularBuffer<T> &operator=(CircularBuffer<T> const &other) {
    if (this == &other)
      return *this;

    if (capacity_ == other.capacity_) {
      Clean();
    } else {
      Deinitialize();
      AllocBody(other.capacity_);
    }

    InitializeBodyFromOther(other);
    return *this;
  }

  int Reserve() const noexcept {
    return capacity_ - size_;
  }

  bool IsFull() const noexcept {
    return capacity_ == size_;
  }

  bool IsLinear() const noexcept {
    return begin_ == 0;
  }

  void SetCapacity(size_t const new_capacity) {
    if (new_capacity == capacity_)
      return;

    if (new_capacity < size_)
      throw std::length_error("Try to non-explicit Cut existing elements");

    auto *old_mem_pool = mem_pool_;
    auto *old_body = body_;
    AllocBody(new_capacity);

    if constexpr (std::is_copy_constructible<T>::value) {
      for (size_t i = 0; i < size_; ++i)
        new(&body_[i]) T(old_body[RealPlace(i)]);
    } else {
      for (size_t i = 0; i < size_; ++i)
        new(&body_[i]) T(std::forward<T>(old_body[RealPlace(i)]));
    }

    begin_ = 0;
    delete[] old_mem_pool;
  }

  void Cut(size_t const new_size) {
    if (new_size > size_)
      throw std::invalid_argument("Wrong size to Cut");

    for (; size_ > new_size; --size_)
      At(size_ - 1).~T();
  }

  void Expand(size_t const new_size, T const &elem) {
    if (new_size <= size_)
      throw std::logic_error("Wrong size to Expand");

    if (new_size > capacity_)
      SetCapacity(new_size);

    while (size_ < new_size)
      PushBack(elem);
  }

  void Resize(size_t const new_size, T const &elem = T()) {
    if (size_ < new_size)
      Expand(new_size, elem);

    if (size_ > new_size)
      Cut(new_size);
  }

  T *Linearize() {
    if (IsLinear())
      return body_;

    auto *old_mem_pool = mem_pool_;
    auto *old_body = body_;
    AllocBody(capacity_);

    if constexpr (std::is_copy_constructible<T>::value) {
      for (size_t i = 0; i < size_; ++i)
        new(&body_[i]) T(old_body[RealPlace(i)]);
    } else {
      for (size_t i = 0; i < size_; ++i)
        new(&body_[i]) T(std::forward<T>(old_body[RealPlace(i)]));
    }

    begin_ = 0;
    delete[] old_mem_pool;
    return body_;
  }

  void Insert(size_t const place, T const &elem) {
    if (IsFull())
      throw std::overflow_error("Try to Insert to full buffer");

    if (place > size_)
      throw std::invalid_argument("Wrong Insert position");

    if (place != size_) { // Need to move tail forward
      for (size_t i = 0; i < size_ - place; ++i) {
        auto const kSource = RealPlace(size_ - i - 1);
        const auto kDest = (kSource + 1) % capacity_;
        if (kDest < size_)
          body_[kDest] = body_[kSource];
        else
          new (&body_[kDest]) T(body_[kSource]);
      }
    }

    const auto kNewPlace = RealPlace(place);
    if (kNewPlace < size_)
      body_[kNewPlace] = elem;
    else
      new (&body_[kNewPlace]) T(elem);
    ++size_;
  }

  void Insert(size_t const place, T &&elem) {
    if (IsFull())
      throw std::overflow_error("Try to Insert to full buffer");

    if (place > size_)
      throw std::invalid_argument("Wrong Insert position");

    if (place != size_) {
      for (size_t i = 0; i < size_ - place; ++i) {
        auto const kSource = RealPlace(size_ - i - 1);
        const auto kDest = (kSource + 1) % capacity_;
        if (kDest < size_)
          body_[kDest] = std::forward<T>(body_[kSource]);
        else
          new(&body_[kDest]) T(std::forward<T>(body_[kSource]));
      }
    }

    const auto kNewPlace = RealPlace(place);
    if (kNewPlace < size_)
      body_[kNewPlace] = std::forward<T>(elem);
    else
      new(&body_[kNewPlace]) T(std::forward<T>(elem));
    ++size_;
  }

  /// [first, last), dont do anything in case first == last
  void Erase(size_t const first, size_t const last) {
    if (first >= size_ || last > size_)
      throw std::length_error("Try to Erase after end");

    if (first > last)
      throw std::invalid_argument("Erasing [first, last), first > last");

    for (size_t i = first; i < last; ++i)
      body_[i].~T();

    if (last < size_)
      for (size_t i = 0; i < size_ - last; ++i)
        body_[RealPlace(first + i)] = body_[RealPlace(first + i + 1)];

    size_ -= last - first;
  }

  bool operator==(CircularBuffer<T> const &other) const {
    if (size_ != other.size_)
      return false;

    for (size_t i = 0; i < size_; ++i)
      if (At(i) != other.At(i))
        return false;

    return true;
  }

  bool operator!=(CircularBuffer<T> const &other) const {
    return !(this->operator==(other));
  }

  void Swap(CircularBuffer<T> &other) noexcept {
    Swap(mem_pool_, other.mem_pool_);
    Swap(capacity_, other.capacity_);
    Swap(begin_, other.begin_);
    Swap(size_, other.size_);
  }

 private:
  T *body_;
  size_t begin_{};
  size_t size_{};
  size_t capacity_{};
  Byte *mem_pool_{};

  size_t RealPlace(size_t const place) const noexcept {
    return (begin_ + place) % capacity_;
  }

  template<class D>
  void Swap(D &left, D &right) const {
    D const kTemp = left;
    left = right;
    right = kTemp;
  }

  void AllocBody(size_t const capacity) {
    capacity_ = capacity;

    if (capacity == 0) {
      mem_pool_ = nullptr;
      body_ = nullptr;
    } else {
      mem_pool_ = new Byte[sizeof(T) * capacity];
      body_ = reinterpret_cast<T *>(mem_pool_);
    }
  }

  void InitializeBodyFromOther(CircularBuffer<T> const &other) {
    begin_ = other.begin_;

    for (size_ = 0; size_ < other.size_; ++size_)
      new (&body_[size_]) T(other.body_[size_]);
  }

  void Deinitialize() {
    Clean();

    if (capacity_ == 0)
      return;

    delete[] mem_pool_;
    mem_pool_ = nullptr;
    body_ = nullptr;
    capacity_ = 0;
  }
};
}