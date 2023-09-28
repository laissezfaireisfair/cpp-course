#pragma once

#include "IStrategy.h"
namespace PrisonerSimulator {
class KindRepeaterStrategy : public IStrategy {
  Decision MakeDecision(IPlayerStatusFacade* playerStatus, int rivalId) override;

 public:
  KindRepeaterStrategy();

  ~KindRepeaterStrategy() override;
};
}