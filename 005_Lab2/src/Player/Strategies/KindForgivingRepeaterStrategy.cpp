#include <random>

#include "Player/Strategies/KindForgivingRepeaterStrategy.h"

namespace PrisonerSimulator {
KindForgivingRepeaterStrategy::KindForgivingRepeaterStrategy() = default;

KindForgivingRepeaterStrategy::~KindForgivingRepeaterStrategy() = default;

Decision KindForgivingRepeaterStrategy::MakeDecision(PrisonerSimulator::IPlayerStrategyFacade* playerStatus, int rivalId) {
  int const kForgiveDiceThreshold = 5;

  static std::random_device random_device;
  static std::default_random_engine engine(random_device());
  static std::uniform_int_distribution<int> uniform_dist(1, 6);

  auto decision = KindRepeaterStrategy::MakeDecision(playerStatus, rivalId);

  if (decision == Decision::Defect){
    auto forgiveDiceResult = uniform_dist(engine);
    if (forgiveDiceResult >= kForgiveDiceThreshold)
      return Decision::Cooperate;
  }

  return decision;
}
}