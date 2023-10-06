#include <iostream>
#include "FastGameState.h"
#include "Game.h"
#include "EndGameState.h"

namespace PrisonerSimulator {
FastGameState::FastGameState(Game* game) : ProcessGameState(game), round(0) {
  auto& all_players = game_->GetPlayers();
  current_rivals_ = std::vector<wptr<IPlayerPlayFacade>>();
  for (auto& player : all_players)
    current_rivals_.push_back(player);
}

bool FastGameState::doStage() {
  RunCompetitionStep();

  player_idx_ += 1;
  rival_idx_ = (rival_idx_ + 1) % current_rivals_.size();

  bool is_round_complete = player_idx_ >= current_rivals_.size();

  if (is_round_complete) {
    player_idx_ = 0;
    rival_idx_ = 1;
    ++round;

    if (round == game_->GetGameRules()->RoundsCount()) {
      auto endGameState = std::make_unique<EndGameState>(game_);
      game_->SwitchGameState(std::move(endGameState));
    }
  }

  return false;
}

FastGameState::~FastGameState() noexcept = default;
}