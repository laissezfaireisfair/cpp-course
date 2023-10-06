#include <iostream>
#include "Game/State/TournamentGameState.h"
#include "Game/Game.h"
#include "Game/State/EndGameState.h"

namespace PrisonerSimulator {
TournamentGameState::TournamentGameState(Game* game) : ProcessGameState(game), round_(0) {
  auto& all_players = game_->GetPlayers();

  for (int i = 0; i < all_players.size() - 2; ++i) {
    for (int j = i + 1; j < all_players.size() - 1; ++j) {
      for (int k = j + 1; k < all_players.size(); ++k) {
        auto triplet = std::vector<PlayerPtr>{all_players[i], all_players[j], all_players[k]};
        waiting_groups_.push_back(triplet);
      }
    }
  }

  current_rivals_ = std::vector<wptr<IPlayerPlayFacade>>();
  LoadNextPlayerGroup();
}

void TournamentGameState::LoadNextPlayerGroup() {
  if (waiting_groups_.empty())
    return;

  auto new_group = waiting_groups_.back();
  waiting_groups_.pop_back();

  current_rivals_.clear();
  for (auto& rival : new_group)
    current_rivals_.push_back(rival);
}

void TournamentGameState::PrintGroupCompetitionResult() {
  std::cout << "Group competition performed." << std::endl;

  for (auto& player : current_rivals_)
    std::cout << player.lock()->GetName() << " "
              << player.lock()->GetId()
              << " Score: " << player.lock()->GetScore() << std::endl;

  std::cout << std::endl;
}

bool TournamentGameState::doStage() {
  RunCompetitionStep();

  player_idx_ += 1;
  rival_idx_ = (rival_idx_ + 1) % current_rivals_.size();

  bool is_round_complete = player_idx_ >= current_rivals_.size();

  if (is_round_complete) {
    player_idx_ = 0;
    rival_idx_ = 1;
    ++round_;

    bool is_last_round = round_ == game_->GetGameRules()->RoundsCount();

    if (is_last_round) {
      if (waiting_groups_.empty()) {
        auto endGameState = std::make_unique<EndGameState>(game_);
        game_->SwitchGameState(std::move(endGameState));
      } else {
        PrintGroupCompetitionResult();
        LoadNextPlayerGroup();
        round_ = 0;
      }
    }
  }

  return false;
}

TournamentGameState::~TournamentGameState() noexcept = default;
}