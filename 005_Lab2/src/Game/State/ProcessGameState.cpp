#include "Game/State/ProcessGameState.h"
#include "Game/Game.h"

namespace PrisonerSimulator {
ProcessGameState::ProcessGameState(PrisonerSimulator::Game* game) :
    IGameState(game),
    player_idx_(0),
    rival_idx_(1),
    current_rivals_(std::vector<wptr<IPlayerPlayFacade>>()) {}

void ProcessGameState::RunCompetitionStep() {
  auto player = current_rivals_[player_idx_].lock();
  auto rival = current_rivals_[rival_idx_].lock();

  int rival_id = rival->GetId();
  int player_id = player->GetId();

  auto playerDecision = player->MakeDecision(rival_id);
  auto rivalDecision = rival->MakeDecision(player_id);

  player->StoreDecision(rival_id, rivalDecision);
  rival->StoreDecision(player_id, playerDecision);

  if (playerDecision == Decision::Cooperate && rivalDecision == Decision::Cooperate) {
    player->UpdateScore(game_->GetGameRules()->CooperationReward(), rival_id);
    rival->UpdateScore(game_->GetGameRules()->CooperationReward(), player_id);
  }

  else if (playerDecision == Decision::Defect && rivalDecision == Decision::Defect) {
    player->UpdateScore(-game_->GetGameRules()->DefectFine(), rival_id);
    rival->UpdateScore(-game_->GetGameRules()->DefectFine(), player_id);
  }

  else if (playerDecision == Decision::Cooperate && rivalDecision == Decision::Defect) {
    player->UpdateScore(-game_->GetGameRules()->CooperationFine(), rival_id);
    rival->UpdateScore(game_->GetGameRules()->DefectReward(), player_id);
  }

  else if (playerDecision == Decision::Defect && rivalDecision == Decision::Cooperate) {
    player->UpdateScore(game_->GetGameRules()->DefectReward(), rival_id);
    rival->UpdateScore(-game_->GetGameRules()->CooperationFine(), player_id);
  }
}
}