#include <vector>
#include "gtest/gtest.h"
#include "CircularBuffer.h"
#include "TestUtils.h"

template<class T> using Container = collections::CircularBuffer<T>;

namespace resize_test {
TEST(ResizeTests, All) {
  auto buffer = std::make_unique<Container<int>>(6,42);
  EXPECT_TRUE(test_utils::CheckBuffer(*buffer, std::vector<int>(6, 42)));

  EXPECT_EQ(buffer->GetSize(), 6);

  buffer->Resize(7);
  EXPECT_EQ(buffer->GetSize(), 7);

  buffer->Resize(6);
  EXPECT_EQ(buffer->GetSize(), 6);

  buffer->Resize(5);
  EXPECT_EQ(buffer->GetSize(), 5);
}
}