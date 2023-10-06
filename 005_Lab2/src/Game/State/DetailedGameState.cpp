#include <iostream>
#include "Game/State/DetailedGameState.h"
#include "Game/Game.h"
#include "Game/State/EndGameState.h"

namespace PrisonerSimulator {
DetailedGameState::DetailedGameState(Game* game) : ProcessGameState(game), round_(0) {
  auto& all_players = game_->GetPlayers();
  current_rivals_ = std::vector<wptr<IPlayerPlayFacade>>();
  for (auto& player : all_players)
    current_rivals_.push_back(player);
}

void DetailedGameState::PrintCompetitionStepInfo() {
  auto player = current_rivals_[player_idx_].lock();
  auto rival = current_rivals_[rival_idx_].lock();

  int player_delta = player->GetLastDelta(rival->GetId());
  int rival_delta = rival->GetLastDelta(player->GetId());

  std::cout << "Step complete:" << std::endl;

  std::cout << "  " << player->GetName() << ": "
            << DecisionToString(player->GetLastDecision(rival->GetId()))
            << ", Delta: " << player_delta
            << " (Score = " << player->GetScore() << ")"
            << std::endl;

  std::cout << "  " << rival->GetName() << ": "
            << DecisionToString(rival->GetLastDecision(player->GetId()))
            << ", Delta: " << rival_delta
            << " (Score = " << rival->GetScore() << ")"
            << std::endl;
}

bool DetailedGameState::doStage() {
  RunCompetitionStep();
  PrintCompetitionStepInfo();

  player_idx_ += 1;
  rival_idx_ = (rival_idx_ + 1) % current_rivals_.size();

  bool is_round_complete = player_idx_ >= current_rivals_.size();

  if (is_round_complete) {
    player_idx_ = 0;
    rival_idx_ = 1;
    std::cout << "Round " << round_ << " finished." << std::endl << std::endl;
    ++round_;

    bool is_game_finished = round_ == game_->GetGameRules()->RoundsCount();

    if (is_game_finished) {
      auto endGameState = std::make_unique<EndGameState>(game_);
      game_->SwitchGameState(std::move(endGameState));
    }
  }

  return false;
}

DetailedGameState::~DetailedGameState() noexcept = default;
}