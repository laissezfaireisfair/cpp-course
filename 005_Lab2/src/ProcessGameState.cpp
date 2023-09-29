#include "ProcessGameState.h"
#include "Game.h"

namespace PrisonerSimulator {
ProcessGameState::ProcessGameState(PrisonerSimulator::Game* game) :
    IGameState(game),
    player_idx_(0),
    rival_idx_(1),
    current_rivals_(std::vector<wptr<IPlayerPlayFacade>>()) {}

bool ProcessGameState::RunCompetitionStep() {
  auto player = current_rivals_[player_idx_];
  auto rival = current_rivals_[rival_idx_];

  auto playerDecision = player.lock()->MakeDecision(rival.lock()->GetId());
  auto rivalDecision = rival.lock()->MakeDecision(player.lock()->GetId());

  player.lock()->StoreDecision(rival.lock()->GetId(), rivalDecision);
  rival.lock()->StoreDecision(player.lock()->GetId(), playerDecision);

  if (playerDecision == Decision::Cooperate && rivalDecision == Decision::Cooperate) {
    player.lock()->UpdateScore(game_->GetGameRules()->CooperationReward());
    rival.lock()->UpdateScore(game_->GetGameRules()->CooperationReward());
  }

  else if (playerDecision == Decision::Defect && rivalDecision == Decision::Defect) {
    player.lock()->UpdateScore(-game_->GetGameRules()->DefectFine());
    rival.lock()->UpdateScore(-game_->GetGameRules()->DefectFine());
  }

  else if (playerDecision == Decision::Cooperate && rivalDecision == Decision::Defect) {
    player.lock()->UpdateScore(-game_->GetGameRules()->CooperationFine());
    rival.lock()->UpdateScore(game_->GetGameRules()->DefectReward());
  }

  else if (playerDecision == Decision::Defect && rivalDecision == Decision::Cooperate) {
    player.lock()->UpdateScore(game_->GetGameRules()->DefectReward());
    rival.lock()->UpdateScore(-game_->GetGameRules()->CooperationFine());
  }

  player_idx_ += 1;
  rival_idx_ = (rival_idx_ + 1) % current_rivals_.size();

  return player_idx_ < current_rivals_.size();
}
}