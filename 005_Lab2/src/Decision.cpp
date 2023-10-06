#include <stdexcept>

#include "Decision.h"

namespace PrisonerSimulator {
std::string DecisionToString(Decision decision) {
  switch (decision) {
    case Decision::Cooperate: return "Cooperate";

    case Decision::Defect: return "Defect";

    default: throw std::invalid_argument("Unknown decision type");
  }
}
}