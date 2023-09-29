#pragma once

#include <memory>
#include <vector>
namespace PrisonerSimulator{
class Configurator{
  std::vector<std::string> strategy_names_;
  std::string mode_name_;
  int rounds_count_;
  int cooperation_reward_;
  int cooperation_fine_;
  int defect_reward_;
  int defect_fine_;

  Configurator();

 public:
  static Configurator & Instance();

  std::vector<std::string> const & GetStrategyNames() const;

  void SetStrategyNames(std::vector<std::string> && strategy_names);

  std::string const & GetModeName() const;

  void SetModeName(std::string && mode_name);

  int GetRoundsCount() const;

  void SetRoundsCount(int rounds_count);

  int GetCooperationReward() const;

  void SetCooperationReward(int cooperation_reward);

  int GetCooperationFine() const;

  void SetCooperationFine(int cooperation_fine);

  int GetDefectReward() const;

  void SetDefectReward(int defect_reward);

  int GetDefectFine() const;

  void SetDefectFine(int defect_fine);

  ~Configurator();
};
}