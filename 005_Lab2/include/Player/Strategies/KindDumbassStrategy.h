#pragma once

#include "IStrategy.h"
namespace PrisonerSimulator {
class KindDumbassStrategy : public IStrategy {
  Decision MakeDecision(IPlayerStrategyFacade* playerStatus, int rivalId) override;

 public:
  KindDumbassStrategy();

  ~KindDumbassStrategy() override;
};
}