#pragma once

#include "KindRepeaterStrategy.h"

namespace PrisonerSimulator {
class KindForgivingRepeaterStrategy : public KindRepeaterStrategy {
 public:
  Decision MakeDecision(IPlayerStrategyFacade* playerStatus, int rivalId) override;

  KindForgivingRepeaterStrategy();

  ~KindForgivingRepeaterStrategy() override;
};
}