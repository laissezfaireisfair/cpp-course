#include <vector>
#include "gtest/gtest.h"
#include "CircularBuffer.h"
#include "TestUtils.h"

template<class T> using Container = collections::CircularBuffer<T>;

namespace capacity_test {
TEST(CapacityTests, All) {
  auto buffer = std::make_unique<Container<int>>(5,42);
  EXPECT_TRUE(test_utils::CheckBuffer(*buffer, std::vector<int>(5, 42)));

  EXPECT_EQ(buffer->GetCapacity(), 5);
  buffer->SetCapacity(6);
  EXPECT_EQ(buffer->GetCapacity(), 6);

  buffer->SetCapacity(5);
  EXPECT_EQ(buffer->GetCapacity(), 5);

  EXPECT_ANY_THROW(buffer->SetCapacity(4));
}
}