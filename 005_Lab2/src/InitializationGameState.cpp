#include "Game.h"
#include "InitializationGameState.h"
#include "PlayerFactory.h"
#include "EndGameState.h"

namespace PrisonerSimulator{
InitializationGameState::InitializationGameState(Game* game) : IGameState(game) {}

InitializationGameState::~InitializationGameState() noexcept = default;

bool InitializationGameState::doStage() {
  auto player_factory = std::make_unique<PlayerFactory>();
  std::string kindRepeaterStrategy = "KindRepeaterStrategy";

  game_->AddPlayer(player_factory->CreatePlayer(kindRepeaterStrategy));
  game_->AddPlayer(player_factory->CreatePlayer(kindRepeaterStrategy));
  game_->AddPlayer(player_factory->CreatePlayer(kindRepeaterStrategy));

  auto game_rules = std::make_unique<GameRules>(3, 5, -7, -10, 10);
  game_->SetGameRules(std::move(game_rules));

  auto endStage = std::make_unique<EndGameState>(game_);
  game_->SwitchGameState(std::move(endStage));

  return false;
}
}