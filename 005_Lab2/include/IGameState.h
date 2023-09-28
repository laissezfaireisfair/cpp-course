#pragma once

#include <memory>

namespace PrisonerSimulator {
class Game;

class IGameState {
 protected:
  Game* game_;

 public:
  explicit IGameState(Game* game);

  /// Returns true if game ended
  virtual bool doStage() = 0;

  virtual ~IGameState() = default;
};
}