#include "gtest/gtest.h"
#include "CircularBuffer.h"

TEST(CreationTest, DefaultConstructor) {
  EXPECT_NO_THROW({
                    auto buffer = std::make_unique<collections::CircularBuffer<int>>();
                  });
}

TEST(CreationTest, CapacityConstructor) {
  EXPECT_NO_THROW({
                    auto buffer = std::make_unique<collections::CircularBuffer<int>>(5);
                  });
}

TEST(CreationTest, SizeValueConstructor) {
  EXPECT_NO_THROW({
                    auto buffer = std::make_unique<collections::CircularBuffer<int>>(3, 4);
                  });
}

TEST(CreationTest, CopyConstructor) {
  EXPECT_NO_THROW({
                    auto buffer = std::make_unique<collections::CircularBuffer<int>>(6, 7);
                    auto buffer2 = std::make_unique<collections::CircularBuffer<int>>(*buffer);
                  });
}