#include "GameRules.h"

namespace PrisonerSimulator {
GameRules::GameRules(int rounds_count,
                     int cooperation_reward,
                     int defect_fine,
                     int cooperation_fine,
                     int defect_reward) {
  rounds_count_ = rounds_count;
  cooperation_reward_ = cooperation_reward;
  cooperation_fine_ = cooperation_fine;
  defect_fine_ = defect_fine;
  defect_reward_ = defect_reward;
}

int GameRules::RoundsCount() const
{
  return rounds_count_;
}

int GameRules::CooperationReward() const
{
  return cooperation_reward_;
}

int GameRules::CooperationFine() const
{
  return cooperation_fine_;
}

int GameRules::DefectReward() const
{
  return defect_reward_;
}

int GameRules::DefectFine() const
{
  return defect_fine_;
}
}