#pragma once

#include "IStrategy.h"
namespace PrisonerSimulator {
class InconsistentStrategy : public IStrategy {
 public:
  Decision MakeDecision(IPlayerStrategyFacade* playerStatus, int rivalId) override;

  InconsistentStrategy();

  ~InconsistentStrategy() override;
};
}