#pragma once

#include <string>

namespace PrisonerSimulator {
enum class Decision {
  Cooperate = 1,
  Defect = 2
};

std::string DecisionToString(Decision decision);
}
