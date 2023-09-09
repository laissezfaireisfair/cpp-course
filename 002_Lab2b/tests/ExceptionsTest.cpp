#include <vector>
#include <string>
#include "gtest/gtest.h"
#include "CircularBuffer.h"

template<class T> using Container = collections::CircularBuffer<T>;

namespace exception_tests {
TEST(ExceptionTests, All) {
  auto buffer = Container<int>(2);
  buffer.PushBack(5);
  auto const kBuffer = buffer;

  EXPECT_ANY_THROW(kBuffer.At(2));
  EXPECT_ANY_THROW(kBuffer.At(1));

  auto str_buffer = Container<std::string>(1);
  std::string const kStrExample = "abc";
  str_buffer.PushBack(kStrExample);
  EXPECT_ANY_THROW(str_buffer.PushBack(kStrExample));

  str_buffer.PopFront();
  EXPECT_TRUE(str_buffer.IsLinear());

  str_buffer.PushBack(kStrExample);
  str_buffer.PopBack();
  EXPECT_TRUE(str_buffer.IsLinear());

  EXPECT_NO_THROW(str_buffer.SetCapacity(1));

  EXPECT_ANY_THROW(str_buffer.Cut(50));
  EXPECT_ANY_THROW(str_buffer.Expand(0, kStrExample));

  EXPECT_ANY_THROW(str_buffer.Erase(2, 1));
  EXPECT_ANY_THROW(str_buffer.Erase(1, 0));
}
}