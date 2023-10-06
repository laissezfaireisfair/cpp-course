#pragma once

#include "IStrategy.h"
namespace PrisonerSimulator {
class EvilRepeaterStrategy : public IStrategy {
  Decision MakeDecision(IPlayerStrategyFacade* playerStatus, int rivalId) override;

 public:
  EvilRepeaterStrategy();

  ~EvilRepeaterStrategy() override;
};
}