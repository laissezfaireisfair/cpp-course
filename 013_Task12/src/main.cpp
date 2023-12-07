#include <iostream>
#include <list>

#include "ListAllocator.h"

using std::list;
using std::cout;
using std::endl;
using task12::ListAllocator;

int main() {
  ListAllocator<int> allocator;
  list<int, ListAllocator<int>> list(allocator);

  int limit = 1000000;
  for (int i = 0; i < limit; ++i)
    list.push_back(i);

  for (auto& node : list)
    cout << node << " ";
  cout << endl;

  return 0;
}
