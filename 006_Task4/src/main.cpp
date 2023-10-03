#include <iostream>

#include "Budget.h"

void PerformEarnRequest(Budget::Budget &budget) {
  Budget::Date from_date;
  Budget::Date to_date;
  int value;
  std::cin >> from_date >> to_date >> value;

  budget.EarnFromToValue(from_date, to_date, value);
}

void PerformComputeRequest(Budget::Budget &budget) {
  Budget::Date from_date;
  Budget::Date to_date;
  std::cin >> from_date >> to_date;

  double income = budget.ComputeIncomeFromTo(from_date, to_date);
  std::cout << income << std::endl;
}

void PerformRequest(Budget::Budget &budget) {
  static const std::string earn_command = "Earn";
  static const std::string compute_command = "ComputeIncome";

  std::string command;
  std::cin >> command;

  if (command == earn_command)
    PerformEarnRequest(budget);
  else if (command == compute_command)
    PerformComputeRequest(budget);
  else
    std::cout << "Unknown command: " << command << std::endl;
}

int main() {
  Budget::Date period_begin(2000, 1, 1);
  Budget::Date period_end(2099, 12, 31);

  Budget::Budget budget(period_begin, period_end);

  int requests_count;
  std::cin >> requests_count;

  for (int i = 0; i < requests_count; ++i)
    PerformRequest(budget);

  return 0;
}
