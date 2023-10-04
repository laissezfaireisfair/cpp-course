#pragma once

#include "ProcessGameState.h"

namespace PrisonerSimulator {
class DetailedGameState : public ProcessGameState {
  int round;

  void PrintCompetitionStepInfo();

 public:
  explicit DetailedGameState(Game* game);

  bool doStage() override;

  ~DetailedGameState() noexcept override;
};
}