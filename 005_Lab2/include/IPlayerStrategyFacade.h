#pragma once

#include <vector>
#include "Decision.h"

namespace PrisonerSimulator {
class IPlayerStrategyFacade {
 public:
  virtual int GetScore() = 0;

  virtual const std::vector<Decision>& GetMyDecisionsByRivalId(int rivalId) = 0;

  virtual const std::vector<Decision>& GetRivalDecisionsById(int rivalId) = 0;

  virtual ~IPlayerStrategyFacade() = default;
};
}