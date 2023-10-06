#pragma once

#include "IStrategy.h"
namespace PrisonerSimulator {
class KindDumbassStrategy : public IStrategy {
 public:
  Decision MakeDecision(IPlayerStrategyFacade* playerStatus, int rivalId) override;

  KindDumbassStrategy();

  ~KindDumbassStrategy() override;
};
}