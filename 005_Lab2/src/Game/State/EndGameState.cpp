#include <iostream>
#include "Game/Game.h"
#include "Game/State/EndGameState.h"

namespace PrisonerSimulator {
EndGameState::EndGameState(Game* game) : IGameState(game) {}

EndGameState::~EndGameState() noexcept = default;

bool EndGameState::doStage() {
  std::cout << "Simulation finished." << std::endl;

  std::cout << "Scores:" << std::endl;
  for (std::weak_ptr<IPlayerPlayFacade> player : game_->GetPlayers()) {
    auto name = player.lock()->GetName();
    auto id = player.lock()->GetId();
    auto score = player.lock()->GetScore();

    std::cout << name << " " << id << ": " << score << std::endl;
  }

  return true;
}
}