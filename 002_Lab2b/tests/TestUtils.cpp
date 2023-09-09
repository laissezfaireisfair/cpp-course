#include "TestUtils.h"

bool test_utils::CheckBuffer(Container<int> &buffer, std::vector<int> const &expected) {
  if (buffer.GetSize() != expected.size())
    return false;

  for (uint64_t i = 0; i < expected.size(); ++i)
    if (buffer[i] != expected[i])
      return false;

  return true;
}

void test_utils::InitBuffer(Container<int> &buffer, std::vector<int> const &values) {
  for (size_t i = 0; i < values.size(); ++i)
    buffer.PushBack(values[i]);
}

bool test_utils::CheckRotationForward(Container<int> &buffer, unsigned int const distance, std::vector<int> const &expected) {
  buffer.RotateForward(distance);
  if (!CheckBuffer(buffer, expected))
    return false;
  return true;
}

bool test_utils::CheckRotationBackward(Container<int> &buffer, unsigned int const distance, std::vector<int> const &expected) {
  buffer.RotateBack(distance);
  if (!CheckBuffer(buffer, expected))
    return false;
  return true;
}