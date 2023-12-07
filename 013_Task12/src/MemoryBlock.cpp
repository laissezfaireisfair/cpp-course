#include <stdexcept>

#include "MemoryBlock.h"

namespace task12 {
using std::make_unique;
using std::invalid_argument;
using std::logic_error;

MemoryBlock::MemoryBlock(size_t capacity) :
    body_{make_unique<byte[]>(capacity)},
    capacity_{capacity},
    used_size_{0},
    objects_stored{0} {
}

MemoryBlock::~MemoryBlock() = default;

MemoryBlock& MemoryBlock::operator=(MemoryBlock&& other) noexcept = default;

size_t MemoryBlock::Capacity() const {
  return capacity_;
}

bool MemoryBlock::IsInBlock(void* ptr) const {
  return body_.get() <= ptr && ptr < body_.get() + capacity_;
}

bool MemoryBlock::DoesHaveEnoughMemory(size_t bytes_required) const {
  return bytes_required <= capacity_ - used_size_;
}

void* MemoryBlock::GetMemory(size_t bytes_required) {
  if (!DoesHaveEnoughMemory(bytes_required))
    throw logic_error("Cannot allocate memory: not enough space in block");

  byte* start = body_.get() + used_size_;
  used_size_ += bytes_required;
  ++objects_stored;
  return start;
}

void MemoryBlock::FreeMemory(void* ptr, size_t size) {
  if (!IsInBlock(ptr))
    throw invalid_argument("Try to free ptr not from block");

  if ((byte*) ptr + size > body_.get() + capacity_)
    throw invalid_argument("Try to free more memory than block has");

  --objects_stored;
  if (objects_stored == 0)
    used_size_ = 0;
}
}