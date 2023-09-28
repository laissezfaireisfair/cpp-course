#pragma once

#include "IGameState.h"

namespace PrisonerSimulator {
class InitializationGameState : public IGameState {
 public:
  explicit InitializationGameState(Game* game);

  ~InitializationGameState() noexcept override;

  bool doStage() override;
};
}