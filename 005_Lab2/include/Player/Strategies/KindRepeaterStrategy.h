#pragma once

#include "IStrategy.h"
namespace PrisonerSimulator {
class KindRepeaterStrategy : public IStrategy {
  Decision MakeDecision(IPlayerStrategyFacade* playerStatus, int rivalId) override;

 public:
  KindRepeaterStrategy();

  ~KindRepeaterStrategy() override;
};
}