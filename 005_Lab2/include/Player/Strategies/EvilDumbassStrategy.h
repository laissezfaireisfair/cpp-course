#pragma once

#include "IStrategy.h"
namespace PrisonerSimulator {
class EvilDumbassStrategy : public IStrategy {
  Decision MakeDecision(IPlayerStrategyFacade* playerStatus, int rivalId) override;

 public:
  EvilDumbassStrategy();

  ~EvilDumbassStrategy() override;
};
}