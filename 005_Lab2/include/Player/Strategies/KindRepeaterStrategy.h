#pragma once

#include "IStrategy.h"
namespace PrisonerSimulator {
class KindRepeaterStrategy : public IStrategy {
 public:
  Decision MakeDecision(IPlayerStrategyFacade* playerStatus, int rivalId) override;

  KindRepeaterStrategy();

  ~KindRepeaterStrategy() override;
};
}