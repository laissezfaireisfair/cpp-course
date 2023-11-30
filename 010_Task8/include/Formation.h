#pragma once

#include <memory>
#include <vector>

namespace task8 {
using std::unique_ptr;
using std::vector;

class Formation {
 public:
  explicit Formation();

  void AddSportsman(int number, int number_after);

  vector<int> GetOrder() const;

  ~Formation();

 private:
  class Impl;
  unique_ptr<Impl> pimpl_;
};
}