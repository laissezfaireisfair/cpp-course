#pragma once

#include "IStrategy.h"
namespace PrisonerSimulator {
class EvilRepeaterStrategy : public IStrategy {
 public:
  Decision MakeDecision(IPlayerStrategyFacade* playerStatus, int rivalId) override;

  EvilRepeaterStrategy();

  ~EvilRepeaterStrategy() override;
};
}