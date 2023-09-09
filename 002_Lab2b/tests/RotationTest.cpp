#include <vector>
#include "gtest/gtest.h"
#include "CircularBuffer.h"
#include "TestUtils.h"

template<class T> using Container = collections::CircularBuffer<T>;

namespace rotation_test {

TEST(RotationTests, All) {
  auto buffer = std::make_unique<Container<int>>(5);

  std::vector<int> values = {0, 1, 2, 3, 4};
  test_utils::InitBuffer(*buffer, values);

  EXPECT_TRUE(test_utils::CheckBuffer(*buffer, values));

  std::vector<int> after_rotation_f = {4, 0, 1, 2, 3};
  EXPECT_TRUE(test_utils::CheckRotationForward(*buffer, 1, after_rotation_f));

  std::vector<int> after_rotation_b = {1, 2, 3, 4, 0};
  EXPECT_TRUE(test_utils::CheckRotationBackward(*buffer, 2, after_rotation_b));

  buffer->SetCapacity(6);
  EXPECT_FALSE(buffer->IsFull());
  EXPECT_ANY_THROW(buffer->RotateBack(1));
  EXPECT_ANY_THROW(buffer->RotateForward(1));
}
}