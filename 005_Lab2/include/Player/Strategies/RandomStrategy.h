#pragma once

#include "IStrategy.h"
namespace PrisonerSimulator {
class RandomStrategy : public IStrategy {
 public:
  Decision MakeDecision(IPlayerStrategyFacade* playerStatus, int rivalId) override;

  RandomStrategy();

  ~RandomStrategy() override;
};
}