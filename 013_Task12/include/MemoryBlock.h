#pragma once

#include <memory>

namespace task12{
using std::unique_ptr;
using byte = char;

class MemoryBlock{
 public:
  MemoryBlock() = delete;

  explicit MemoryBlock(size_t capacity);

  MemoryBlock(MemoryBlock const& other) = delete;

  ~MemoryBlock();

  MemoryBlock& operator=(MemoryBlock const& other) = delete;

  MemoryBlock& operator=(MemoryBlock && other) noexcept;

  size_t Capacity() const;

  bool IsInBlock(void* ptr) const;

  bool DoesHaveEnoughMemory(size_t bytes_required) const;

  void* GetMemory(size_t bytes_required);

  void FreeMemory(void* ptr, size_t size);

 private:
  unique_ptr<byte[]> body_;

  size_t capacity_;

  size_t used_size_;

  int objects_stored;
};
}