#include <vector>
#include "gtest/gtest.h"
#include "CircularBuffer.h"

template<class T> using Container = collections::CircularBuffer<T>;

namespace unique_ptr_tests {
TEST(UniquePtrTests, All) {
  auto buffer = Container<std::unique_ptr<int>>(1);

  auto ptr = std::make_unique<int>(5);

  EXPECT_NO_THROW(buffer.PushBack(std::move(ptr)));
}
}