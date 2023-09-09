#include <vector>
#include "gtest/gtest.h"
#include "CircularBuffer.h"

template<class T> using Container = collections::CircularBuffer<T>;

TEST(InfoMethods, All) {
  auto buffer = std::make_unique<Container<int>>(5);

  EXPECT_FALSE(buffer->IsFull());
  EXPECT_TRUE(buffer->IsEmpty());
  EXPECT_ANY_THROW(buffer->PopFront());
  EXPECT_ANY_THROW(buffer->PopBack());
  EXPECT_EQ(buffer->GetSize(), 0);
  EXPECT_EQ(buffer->GetCapacity(), 5);
  EXPECT_ANY_THROW(buffer->At(1));
  EXPECT_ANY_THROW(buffer->At(10));
  EXPECT_ANY_THROW(buffer->GetFront());
  EXPECT_ANY_THROW(buffer->GetBack());

  buffer->PushBack(2);

  EXPECT_EQ(buffer->At(0), buffer->GetFront());
  EXPECT_EQ(buffer->GetFront(), 2);
  EXPECT_FALSE(buffer->IsEmpty());
  EXPECT_FALSE(buffer->IsFull());

  for (size_t i = 1; i < buffer->GetCapacity(); ++i)
    buffer->PushBack(i);

  EXPECT_TRUE(buffer->IsFull());
  EXPECT_ANY_THROW(buffer->PushBack(1));
  EXPECT_ANY_THROW(buffer->PushFront(1));
}