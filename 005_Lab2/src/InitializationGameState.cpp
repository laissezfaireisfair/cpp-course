#include "Game.h"
#include "InitializationGameState.h"
#include "PlayerFactory.h"
#include "EndGameState.h"
#include "Configurator.h"
#include "DetailedGameState.h"

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
  else {
    auto endStage = std::make_unique<EndGameState>(game_);
    game_->SwitchGameState(std::move(endStage));
  }

  return false;
}
}