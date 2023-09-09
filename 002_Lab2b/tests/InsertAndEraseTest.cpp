#include <vector>
#include "gtest/gtest.h"
#include "CircularBuffer.h"
#include "TestUtils.h"

template<class T> using Container = collections::CircularBuffer<T>;

namespace comparison_tests {
TEST(InsertAndEraseTests, All) {
  auto buffer = std::make_unique<Container<int>>(5, 42);
  auto expected = std::vector<int>(5, 42);
  EXPECT_TRUE(test_utils::CheckBuffer(*buffer, expected));
  buffer->SetCapacity(6);

  buffer->Insert(1, 54);
  expected.insert(expected.begin() + 1, 54);
  EXPECT_TRUE(test_utils::CheckBuffer(*buffer, expected));

  buffer->Erase(2, 4);
  expected.erase(expected.begin() + 2, expected.begin() + 4);
  EXPECT_TRUE(test_utils::CheckBuffer(*buffer, expected));
}
}