#pragma once

#include <string>

#include "Decision.h"
namespace PrisonerSimulator {
class IPlayerPlayFacade {
 public:
  virtual Decision MakeDecision(int rivalId) = 0;

  virtual void StoreDecision(int rivalId, Decision decision) = 0;

  virtual void UpdateScore(int delta, int rivalId) = 0;

  virtual int GetId() = 0;

  virtual std::string GetName() = 0;

  virtual Decision GetLastDecision(int rivalId) = 0;

  virtual int GetScore() = 0;

  virtual int GetLastDelta(int rivalId) = 0;

  virtual ~IPlayerPlayFacade() = default;
};
}