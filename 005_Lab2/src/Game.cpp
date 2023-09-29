#include "Game.h"
#include "InitializationGameState.h"

namespace PrisonerSimulator {
Game::Game() :
    game_rules_(nullptr),
    players_(std::vector<sptr<IPlayerPlayFacade>>()),
    game_state_(std::make_unique<InitializationGameState>(this)) {
}

Game::~Game() = default;

void Game::AddPlayer(uptr<PrisonerSimulator::IPlayerPlayFacade>&& player) {
  players_.push_back(std::move(player));
}

void Game::SetGameRules(uptr<PrisonerSimulator::GameRules>&& game_rules) {
  game_rules_ = std::move(game_rules);
}

void Game::SwitchGameState(uptr<PrisonerSimulator::IGameState>&& game_state) {
  game_state_ = std::move(game_state);
}

uptr<GameRules>& Game::GetGameRules() {
  return game_rules_;
}

std::vector<sptr<IPlayerPlayFacade>>& Game::GetPlayers() {
  return players_;
}

void Game::Run() {
  while (true) {
    bool isEnded = game_state_->doStage();
    if (isEnded)
      break;
  }
}
}