#include "Game/Game.h"
#include "Game/State/InitializationGameState.h"
#include "Player/PlayerFactory.h"
#include "Game/State/EndGameState.h"
#include "Configurator.h"
#include "Game/State/DetailedGameState.h"
#include "Game/State/FastGameState.h"
#include "Game/State/TournamentGameState.h"

namespace PrisonerSimulator{
InitializationGameState::InitializationGameState(Game* game) : IGameState(game) {}

InitializationGameState::~InitializationGameState() noexcept = default;

bool InitializationGameState::doStage() {
  auto player_factory = std::make_unique<PlayerFactory>();
  auto& configurator = Configurator::Instance();

  auto& strategies = configurator.GetStrategyNames();
  for (auto& strategy: strategies)
    game_->AddPlayer(player_factory->CreatePlayer(strategy));

  auto game_rules = std::make_unique<GameRules>(configurator.GetRoundsCount(),
                                                configurator.GetCooperationReward(),
                                                configurator.GetDefectFine(),
                                                configurator.GetCooperationFine(),
                                                configurator.GetDefectReward());
  game_->SetGameRules(std::move(game_rules));

  if (configurator.GetModeName() == "detailed"){
    auto gameStage = std::make_unique<DetailedGameState>(game_);
    game_->SwitchGameState(std::move(gameStage));
  }

  else if (configurator.GetModeName() == "fast"){
    auto gameStage = std::make_unique<FastGameState>(game_);
    game_->SwitchGameState(std::move(gameStage));
  }

  else if (configurator.GetModeName() == "tournament"){
    auto gameStage = std::make_unique<TournamentGameState>(game_);
    game_->SwitchGameState(std::move(gameStage));
  }

  else {
    auto endStage = std::make_unique<EndGameState>(game_);
    game_->SwitchGameState(std::move(endStage));
  }

  return false;
}
}