#pragma once

#include <string>

#include "Decision.h"
namespace PrisonerSimulator {
class IPlayerPlayFacade {
 public:
  virtual Decision MakeDecision(int rivalId) = 0;

  virtual void StoreDecision(int rivalId, Decision decision) = 0;

  virtual void UpdateScore(int delta) = 0;

  virtual int GetId() = 0;

  virtual std::string GetName() = 0;

  virtual Decision LastDecision(int rivalId) = 0;

  virtual int GetScore() = 0;

  virtual ~IPlayerPlayFacade() = default;
};
}