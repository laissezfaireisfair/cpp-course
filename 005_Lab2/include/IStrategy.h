#pragma once

#include "IPlayerStatusFacade.h"
#include "Decision.h"

namespace PrisonerSimulator {
class IStrategy {
 public:
  virtual Decision MakeDecision(IPlayerStatusFacade* playerStatus, int rivalId) = 0;

  virtual ~IStrategy() = default;
};
}