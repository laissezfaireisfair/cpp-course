#include "Budget.h"

namespace Budget {
Budget::Budget(const Date &period_begin, const Date &period_end) :
    period_begin_(period_begin),
    incomes_(period_end - period_begin, 0) {
}

double &Budget::At(const Date &date) {
  int shift_from_begin = date - period_begin_;
  return incomes_[shift_from_begin];
}

void Budget::EarnFromToValue(Date &from, Date &to, double value) {
  int period_days = to - from + 1;
  double profit_per_day = value / period_days;
  for (Date date = from; date <= to; ++date)  // Might be optimized with int index
    At(date) += profit_per_day;
}

double Budget::ComputeIncomeFromTo(Date &from, Date &to) {
  double sum = 0;
  for (Date date = from; date <= to; ++date)  // Might be optimized with int index
    sum += At(date);
  return sum;
}

Budget::~Budget() = default;
}