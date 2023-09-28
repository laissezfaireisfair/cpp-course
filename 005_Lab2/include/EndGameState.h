#pragma once

#include "IGameState.h"

namespace PrisonerSimulator {
class EndGameState : public IGameState {
 public:
  explicit EndGameState(Game* game);

  ~EndGameState() noexcept override;

  bool doStage() override;
};
}