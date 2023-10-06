#include <random>

#include "Player/Strategies/RandomStrategy.h"

namespace PrisonerSimulator {
RandomStrategy::RandomStrategy() = default;

RandomStrategy::~RandomStrategy() = default;

Decision RandomStrategy::MakeDecision(PrisonerSimulator::IPlayerStrategyFacade* playerStatus, int rivalId) {
  static std::random_device random_device;
  static std::default_random_engine engine(random_device());
  static std::uniform_int_distribution<int> uniform_dist(0, 1);

  return uniform_dist(engine) == 1
         ? Decision::Cooperate
         : Decision::Defect;
}
}