#pragma once

#include <list>

#include "MemoryBlock.h"

namespace task12 {
using std::shared_ptr;
using std::make_shared;
using std::list;
using std::size_t;
using std::max;

template<class T>
struct ListAllocator {
  typedef T value_type;

  ListAllocator() noexcept:
      memory_blocks_{make_shared<list<MemoryBlock>>()} {
  }

  template<class U>
  explicit ListAllocator(ListAllocator<U> const& other) noexcept :
      memory_blocks_{other.memory_blocks_} {
  }

  template<class U>
  bool operator==(const ListAllocator<U>& other) const noexcept {
    return memory_blocks_.get() == other.memory_blocks_.get();
  }

  template<class U>
  bool operator!=(const ListAllocator<U>& other) const noexcept {
    return !this->operator==(other);
  }

  T* allocate(const size_t n) {
    size_t bytes_required = n * sizeof(T);

    for (auto& block : *memory_blocks_)
      if (block.DoesHaveEnoughMemory(n))
        return reinterpret_cast<T*>(block.GetMemory(bytes_required));

    auto capacity = memory_blocks_->empty()
                    ? bytes_required
                    : max(2 * memory_blocks_->back().Capacity(), bytes_required);
    auto& new_block = memory_blocks_->emplace_back(capacity);
    return reinterpret_cast<T*>(new_block.GetMemory(bytes_required));
  }

  void deallocate(T* const p, size_t size) {
    for (auto& block : *memory_blocks_)
      if (block.IsInBlock(reinterpret_cast<void*>(p)))
        block.FreeMemory(reinterpret_cast<void*>(p), size * sizeof(T));
  }

 private:
  shared_ptr<list<MemoryBlock>> memory_blocks_;

  template<class U> friend
  struct ListAllocator;
};
}