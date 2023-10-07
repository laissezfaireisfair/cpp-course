#include "Configurator.h"

namespace PrisonerSimulator {
Configurator& Configurator::Instance() {
  static Configurator instance_;
  return instance_;
}

Configurator::Configurator() :
    strategy_names_(std::vector<std::string>{"KindRepeaterStrategy", "KindRepeaterStrategy", "KindRepeaterStrategy"}),
    mode_name_("detailed"),
    rounds_count_(5),
    cooperation_reward_(5),
    cooperation_fine_(10),
    defect_reward_(10),
    defect_fine_(7) {
}

std::vector<std::string> const& Configurator::GetStrategyNames() const {
  return strategy_names_;
}

void Configurator::SetStrategyNames(std::vector<std::string>&& strategy_names) {
  strategy_names_ = std::move(strategy_names);
}

std::string const& Configurator::GetModeName() const {
  return mode_name_;
}

void Configurator::SetModeName(std::string&& mode_name) {
  mode_name_ = std::move(mode_name);
}

int Configurator::GetRoundsCount() const {
  return rounds_count_;
}

void Configurator::SetRoundsCount(int rounds_count) {
  rounds_count_ = rounds_count;
}

int Configurator::GetCooperationReward() const {
  return cooperation_reward_;
}

void Configurator::SetCooperationReward(int cooperation_reward) {
  cooperation_reward_ = cooperation_reward;
}

int Configurator::GetCooperationFine() const {
  return cooperation_fine_;
}

void Configurator::SetCooperationFine(int cooperation_fine) {
  cooperation_fine_ = cooperation_fine;
}

int Configurator::GetDefectReward() const {
  return defect_reward_;
}

void Configurator::SetDefectReward(int defect_reward) {
  defect_reward_ = defect_reward;
}

int Configurator::GetDefectFine() const {
  return defect_fine_;
}

void Configurator::SetDefectFine(int defect_fine) {
  defect_fine_ = defect_fine;
}

Configurator::~Configurator() = default;
}