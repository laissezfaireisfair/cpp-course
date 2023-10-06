#pragma once

#include "IStrategy.h"
namespace PrisonerSimulator {
class RandomStrategy : public IStrategy {
  Decision MakeDecision(IPlayerStrategyFacade* playerStatus, int rivalId) override;

 public:
  RandomStrategy();

  ~RandomStrategy() override;
};
}