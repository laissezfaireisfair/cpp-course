#include <vector>
#include "gtest/gtest.h"
#include "CircularBuffer.h"
#include "TestUtils.h"

template<class T> using Container = collections::CircularBuffer<T>;

namespace linearize_test {
TEST(LinearizeTests, All) {
  auto buffer = std::make_unique<Container<int>>(5,42);
  EXPECT_TRUE(test_utils::CheckBuffer(*buffer, std::vector<int>(5, 42)));

  EXPECT_TRUE(buffer->IsLinear());

  buffer->PopFront();

  EXPECT_FALSE(buffer->IsLinear());

  buffer->Linearize();

  EXPECT_TRUE(buffer->IsLinear());

  EXPECT_NO_THROW(buffer->Linearize());
}
}