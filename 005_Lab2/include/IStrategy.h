#pragma once

#include "IPlayerStrategyFacade.h"
#include "Decision.h"

namespace PrisonerSimulator {
class IStrategy {
 public:
  virtual Decision MakeDecision(IPlayerStrategyFacade* playerStatus, int rivalId) = 0;

  virtual ~IStrategy() = default;
};
}