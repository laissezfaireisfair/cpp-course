#include <vector>
#include "gtest/gtest.h"
#include "CircularBuffer.h"

template<class T> using Container = collections::CircularBuffer<T>;

namespace comparison_tests {
TEST(ComparisonTests, All) {
  auto buffer = Container<int>(5,42);
  auto buffer2 = Container<int>(5,54);

  EXPECT_FALSE(buffer == buffer2);
  EXPECT_TRUE(buffer != buffer2);

  for (size_t i = 0; i < buffer2.GetSize(); ++i)
    buffer[i] = buffer2[i];

  EXPECT_FALSE(buffer != buffer2);
  EXPECT_TRUE(buffer == buffer2);
}
}