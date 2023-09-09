#include <vector>
#include "gtest/gtest.h"
#include "CircularBuffer.h"
#include "TestUtils.h"

template<class T> using Container = collections::CircularBuffer<T>;

TEST(InitAndPushTest, Initialize) {
  EXPECT_NO_THROW({
                    auto buffer = std::make_unique<Container<int>>(5, 3);
                    auto expected = std::make_unique<std::vector<int>>(5, 3);
                    EXPECT_TRUE(test_utils::CheckBuffer(*buffer, *expected));
                  });
}

TEST(InitAndPushTest, PushBack) {
  std::vector<int> expected{5, 3};
  EXPECT_NO_THROW({
                    auto buffer = std::make_unique<Container<int>>(2);
                    buffer->PushBack(5);
                    buffer->PushBack(3);
                    EXPECT_TRUE(test_utils::CheckBuffer(*buffer, expected));
                  });
}

TEST(InitAndPushTest, PushFront) {
  std::vector<int> expected{3, 5};
  EXPECT_NO_THROW({
                    auto buffer = std::make_unique<Container<int>>(2);
                    buffer->PushFront(5);
                    buffer->PushFront(3);
                    EXPECT_TRUE(test_utils::CheckBuffer(*buffer, expected));
                  });
}

