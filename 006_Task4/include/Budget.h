#pragma once

#include <vector>

#include "Date.h"

namespace Budget {
class Budget {
 private:
  Date period_begin_;
  std::vector<double> incomes_;

 public:
  Budget(Date const &period_begin, Date const &period_end);

  double &At(Date const &date);

  void EarnFromToValue(Date &from, Date &to, double value);

  double ComputeIncomeFromTo(Date &from, Date &to);

  ~Budget();
};
}