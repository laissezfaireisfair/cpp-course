#pragma once

namespace PrisonerSimulator {
class GameRules {
  int rounds_count_;
  int cooperation_reward_;
  int cooperation_fine_;
  int defect_fine_;
  int defect_reward_;

 public:
  GameRules(int rounds_count, int cooperation_reward, int defect_fine, int cooperation_fine, int defect_reward);

  int RoundsCount() const;

  int CooperationReward() const;

  int CooperationFine() const;

  int DefectReward() const;

  int DefectFine() const;
};
}