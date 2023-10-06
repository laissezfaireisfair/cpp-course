#include "Player/Strategies/KindRepeaterStrategy.h"

namespace PrisonerSimulator {
KindRepeaterStrategy::KindRepeaterStrategy() = default;

KindRepeaterStrategy::~KindRepeaterStrategy() = default;

Decision KindRepeaterStrategy::MakeDecision(PrisonerSimulator::IPlayerStrategyFacade* playerStatus, int rivalId) {
  auto rival_decisions = playerStatus->GetRivalDecisionsById(rivalId);
  if (rival_decisions.empty())
    return Decision::Cooperate;

  return rival_decisions.back();
}
}