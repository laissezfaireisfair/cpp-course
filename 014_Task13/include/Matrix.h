#pragma once

#include <map>
#include <vector>

namespace task13 {
using std::map;
using std::pair;
using std::string;
using std::vector;
using std::size_t;
using std::make_pair;

template<class T, T kDefault_value>
class Matrix {
 public:
  Matrix() :
      body_{} {
  }

  class Elem {
   public:
    Elem(Matrix& matrix, size_t row, size_t column) :
        matrix_{matrix},
        row_{row},
        column_{column} {
    }

    operator T() const // NOLINT(*-explicit-constructor)
    {
      auto index = make_pair(row_, column_);
      if (matrix_.body_.contains(index))
        return matrix_.body_.at(index);

      return kDefault_value;
    }

    Elem& operator=(T value) {
      if (value == kDefault_value)
        return *this;

      auto index = make_pair(row_, column_);
      matrix_.body_[index] = std::forward<T>(value);
      return *this;
    }

   private:
    Matrix& matrix_;

    size_t row_;

    size_t column_;
  };

  Elem operator()(size_t row, size_t column) {
    return Elem(*this, row, column);
  }

  size_t NonDefaultElemsCount() const {
    return body_.size();
  }

  vector<Elem> GetNonDefaultElems() {
    vector<Elem> elems;
    for (auto& key_value : body_)
      elems.emplace_back(*this, key_value.first.first, key_value.first.second);
    return elems;
  }

 private:
  map<pair<size_t, size_t>, T> body_;  // Could use unordered_map here, but it would require hash for pairs
};
}