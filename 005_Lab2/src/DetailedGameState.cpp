#include <iostream>
#include "DetailedGameState.h"
#include "Game.h"
#include "EndGameState.h"

namespace PrisonerSimulator {
DetailedGameState::DetailedGameState(Game* game) : ProcessGameState(game), round(0) {
  auto& all_players = game_->GetPlayers();
  current_rivals_ = std::vector<wptr<IPlayerPlayFacade>>();
  for (auto& player : all_players)
    current_rivals_.push_back(player);
}

void DetailedGameState::PrintCompetitionStepInfo() {
  auto player = current_rivals_[player_idx_].lock();
  auto rival = current_rivals_[rival_idx_].lock();

  int playerDelta = player->GetLastDelta(rival->GetId());
  int rivalDelta = rival->GetLastDelta(player->GetId());

  std::cout << "Step complete:" << std::endl;

  std::cout << "  " << player->GetName() << ": "
            << DecisionToString(player->GetLastDecision(rival->GetId()))
            << ", Delta: " << playerDelta
            << " (Score = " << player->GetScore() << ")"
            << std::endl;

  std::cout << "  " << rival->GetName() << ": "
            << DecisionToString(rival->GetLastDecision(player->GetId()))
            << ", Delta: " << rivalDelta
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
    std::cout << "Round " << round << " finished." << std::endl;
    ++round;

    if (round == game_->GetGameRules()->RoundsCount()) {
      auto endGameState = std::make_unique<EndGameState>(game_);
      game_->SwitchGameState(std::move(endGameState));
    }
  }

  return false;
}

DetailedGameState::~DetailedGameState() noexcept = default;
}