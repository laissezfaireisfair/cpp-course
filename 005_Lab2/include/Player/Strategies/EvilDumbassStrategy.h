#pragma once

#include "IStrategy.h"
namespace PrisonerSimulator {
class EvilDumbassStrategy : public IStrategy {
 public:
  Decision MakeDecision(IPlayerStrategyFacade* playerStatus, int rivalId) override;

  EvilDumbassStrategy();

  ~EvilDumbassStrategy() override;
};
}