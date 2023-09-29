#include "DetailedGameState.h"
#include "Game.h"
#include "EndGameState.h"

namespace PrisonerSimulator {
DetailedGameState::DetailedGameState(Game* game) : ProcessGameState(game), round(0) {
  auto& all_players = game_->GetPlayers();
  current_rivals_ = std::vector<wptr<IPlayerPlayFacade>>(all_players.size());
  for (auto& player : all_players)
    current_rivals_.push_back(player);
}

bool DetailedGameState::doStage() {
  bool is_round_complete = RunCompetitionStep();
  // TODO: Print step info

  if (is_round_complete) {
    // TODO: Print round info
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

DetailedGameState::~DetailedGameState() noexcept = default;
}