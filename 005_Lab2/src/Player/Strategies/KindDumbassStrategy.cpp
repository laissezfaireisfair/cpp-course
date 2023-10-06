#include "Player/Strategies/KindDumbassStrategy.h"

namespace PrisonerSimulator {
KindDumbassStrategy::KindDumbassStrategy() = default;

KindDumbassStrategy::~KindDumbassStrategy() = default;

Decision KindDumbassStrategy::MakeDecision(PrisonerSimulator::IPlayerStrategyFacade* playerStatus, int rivalId) {
  return Decision::Cooperate;
}
}