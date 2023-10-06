#include "Player/Strategies/InconsistentStrategy.h"

namespace PrisonerSimulator {
InconsistentStrategy::InconsistentStrategy() = default;

InconsistentStrategy::~InconsistentStrategy() = default;

Decision InconsistentStrategy::MakeDecision(PrisonerSimulator::IPlayerStrategyFacade* playerStatus, int rivalId) {
  auto my_decisions = playerStatus->GetMyDecisionsByRivalId(rivalId);
  if (my_decisions.empty())
    return Decision::Cooperate;

  return my_decisions.back() == Decision::Cooperate
         ? Decision::Defect
         : Decision::Cooperate;
}
}