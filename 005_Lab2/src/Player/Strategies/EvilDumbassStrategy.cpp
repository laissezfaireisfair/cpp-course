#include "Player/Strategies/EvilDumbassStrategy.h"

namespace PrisonerSimulator {
EvilDumbassStrategy::EvilDumbassStrategy() = default;

EvilDumbassStrategy::~EvilDumbassStrategy() = default;

Decision EvilDumbassStrategy::MakeDecision(PrisonerSimulator::IPlayerStrategyFacade* playerStatus, int rivalId) {
  return Decision::Defect;
}
}