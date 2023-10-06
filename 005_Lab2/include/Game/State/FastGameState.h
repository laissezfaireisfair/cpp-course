#pragma once

#include "ProcessGameState.h"

namespace PrisonerSimulator {
class FastGameState : public ProcessGameState {
  int round;

 public:
  explicit FastGameState(Game* game);

  bool doStage() override;

  ~FastGameState() noexcept override;
};
}