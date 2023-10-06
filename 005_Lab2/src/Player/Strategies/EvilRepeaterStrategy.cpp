#include "Player/Strategies/EvilRepeaterStrategy.h"

namespace PrisonerSimulator {
EvilRepeaterStrategy::EvilRepeaterStrategy() = default;

EvilRepeaterStrategy::~EvilRepeaterStrategy() = default;

Decision EvilRepeaterStrategy::MakeDecision(PrisonerSimulator::IPlayerStrategyFacade* playerStatus, int rivalId) {
  auto rivalDecisions = playerStatus->GetRivalDecisionsById(rivalId);
  if (rivalDecisions.empty())
    return Decision::Defect;

  return rivalDecisions.back();
}
}