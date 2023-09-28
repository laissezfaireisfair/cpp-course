#include "Game.h"
#include "EndGameState.h"

namespace PrisonerSimulator{
EndGameState::EndGameState(Game* game) : IGameState(game) {}

EndGameState::~EndGameState() noexcept = default;

bool  EndGameState::doStage() {
  return true;
}
}