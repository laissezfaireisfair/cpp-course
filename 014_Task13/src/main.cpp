#include <iostream>

#include "Matrix.h"

using std::cout;
using std::endl;
using task13::Matrix;

int main() {
  Matrix<int, 0> matrix;

  matrix(1, 100) = 3;
  cout << "Three expected: " << matrix(1, 100) << endl;

  for (int i = 0; i < 10000; ++i)
    matrix(i, i) = i;

  cout << "Non-default elems count: " << matrix.NonDefaultElemsCount() << endl;

  auto non_defaults = matrix.GetNonDefaultElems();
  for (auto& elem : non_defaults)
    cout << elem << " ";
  cout << endl;

  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j)
      cout << matrix(i, j) << " ";

    cout << endl;
  }

  return 0;
}
