#include "Player/Strategies/EvilRepeaterStrategy.h"

namespace PrisonerSimulator {
EvilRepeaterStrategy::EvilRepeaterStrategy() = default;

EvilRepeaterStrategy::~EvilRepeaterStrategy() = default;

Decision EvilRepeaterStrategy::MakeDecision(PrisonerSimulator::IPlayerStrategyFacade* playerStatus, int rivalId) {
  auto rival_decisions = playerStatus->GetRivalDecisionsById(rivalId);
  if (rival_decisions.empty())
    return Decision::Defect;

  return rival_decisions.back();
}
}