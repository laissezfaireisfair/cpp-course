#include <map>
#include <algorithm>

#include "Formation.h"

namespace task8 {
using std::make_unique;
using std::map;
using std::reverse;

class Formation::Impl {
 public:
  explicit Impl() :
      last_number_{0},
      is_empty_{true},
      previous_{} {
  }

  void AddSportsman(int number, int number_after) {
    if (is_empty_) {
      last_number_ = number;
      previous_[number] = kTerminator;
      is_empty_ = false;
      return;
    }

    if (previous_.contains(number_after)) {
      previous_[number] = previous_[number_after];
      previous_[number_after] = number;
      return;
    }

    previous_[number] = last_number_;
    last_number_ = number;
  }

  vector<int> GetOrder() const {
    vector<int> order;

    for (int i = last_number_; i != kTerminator; i = previous_.at(i)) {
      order.push_back(i);
    }

    reverse(order.begin(), order.end());

    return order;
  }

  ~Impl() = default;
 private:
  int last_number_;

  bool is_empty_;

  map<int, int> previous_;

  int const kTerminator = INT_MAX;
};

Formation::Formation() :
    pimpl_{make_unique<Impl>()} {
}

void Formation::AddSportsman(int number, int number_after) {
  pimpl_->AddSportsman(number, number_after);
}

vector<int> Formation::GetOrder() const {
  return pimpl_->GetOrder();
}

Formation::~Formation() = default;
}