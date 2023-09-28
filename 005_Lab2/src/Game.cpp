#include "Game.h"
#include "InitializationGameState.h"

namespace PrisonerSimulator{
Game::Game() {
  game_rules_ = nullptr;
  players = std::vector<uptr<IPlayerPlayFacade>>();
  game_state_ = std::make_unique<InitializationGameState>(this);
}

Game::~Game() {
  players.~vector();
  game_state_.reset();
}

void Game::AddPlayer(uptr<PrisonerSimulator::IPlayerPlayFacade>&& player) {
  players.push_back(std::move(player));
}

void Game::SetGameRules(uptr<PrisonerSimulator::GameRules>&& game_rules) {
  game_rules_.reset();
  game_rules_ = std::move(game_rules);
}

void Game::SwitchGameState(uptr<PrisonerSimulator::IGameState>&& game_state) {
  game_state_.reset();
  game_state_ = std::move(game_state);
}

void Game::Run() {
  game_state_->doStage();
}
}