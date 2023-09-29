#include "KindRepeaterStrategy.h"

namespace PrisonerSimulator {
KindRepeaterStrategy::KindRepeaterStrategy() = default;

KindRepeaterStrategy::~KindRepeaterStrategy() = default;

Decision KindRepeaterStrategy::MakeDecision(PrisonerSimulator::IPlayerStrategyFacade* playerStatus, int rivalId) {
  auto rivalDecisions = playerStatus->GetRivalDecisionsById(rivalId);
  if (rivalDecisions.empty())
    return Decision::Cooperate;

  return rivalDecisions.back();
}
}