#include <iostream>
#include "CircularBuffer.h"

template<class T> using Container = collections::CircularBuffer<T>;

int main()
{
  auto buffer = std::make_unique<Container<int>>(5);

  for (int i = 0; i < 5; ++i)
    buffer->PushBack(i);

  auto linearized = buffer->Linearize();
  for (size_t i = 0; i < buffer->GetSize(); ++i)
    std::cout << linearized[i] << " ";

  return 0;
}