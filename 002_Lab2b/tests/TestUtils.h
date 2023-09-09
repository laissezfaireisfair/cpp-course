#pragma once

#include <vector>
#include "CircularBuffer.h"

namespace test_utils {
template<class T> using Container = collections::CircularBuffer<T>;

bool CheckBuffer(Container<int> &buffer, std::vector<int> const &expected);

void InitBuffer(Container<int> &buffer, std::vector<int> const &values);

bool CheckRotationForward(Container<int> &buffer, unsigned int const distance, std::vector<int> const &expected);

bool CheckRotationBackward(Container<int> &buffer, unsigned int const distance, std::vector<int> const &expected);
}