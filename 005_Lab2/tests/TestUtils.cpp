#include "Configurator.h"
#include "TestUtils.h"

namespace Tests {
void TestUtils::SetDefaultTournamentConfiguration(bool add_random) {
  auto& configurator = PrisonerSimulator::Configurator::Instance();

  configurator.SetModeName("tournament");

  configurator.SetRoundsCount(5);

  auto strategy_names = std::vector<std::string>{
      "EvilDumbassStrategy",
      "EvilRepeaterStrategy",
      "InconsistentStrategy",
      "KindDumbassStrategy",
      "KindForgivingRepeaterStrategy",
      "KindRepeaterStrategy"};
  if (add_random)
    strategy_names.emplace_back("RandomStrategy");
  configurator.SetStrategyNames(std::move(strategy_names));

  configurator.SetCooperationReward(5);
  configurator.SetCooperationFine(7);
  configurator.SetDefectFine(7);
  configurator.SetDefectReward(3);
}

void TestUtils::SetDefaultFastConfiguration() {
  auto& configurator = PrisonerSimulator::Configurator::Instance();

  configurator.SetModeName("fast");

  configurator.SetRoundsCount(5);

  auto strategy_names = std::vector<std::string>{
      "EvilRepeaterStrategy",
      "KindForgivingRepeaterStrategy",
      "KindRepeaterStrategy"};
  configurator.SetStrategyNames(std::move(strategy_names));

  configurator.SetCooperationReward(5);
  configurator.SetCooperationFine(7);
  configurator.SetDefectFine(7);
  configurator.SetDefectReward(3);
}

void TestUtils::SetDefaultDetailedConfiguration() {
  auto& configurator = PrisonerSimulator::Configurator::Instance();

  configurator.SetModeName("detailed");

  configurator.SetRoundsCount(5);

  auto strategy_names = std::vector<std::string>{
      "EvilRepeaterStrategy",
      "KindForgivingRepeaterStrategy",
      "KindRepeaterStrategy"};
  configurator.SetStrategyNames(std::move(strategy_names));

  configurator.SetCooperationReward(5);
  configurator.SetCooperationFine(7);
  configurator.SetDefectFine(7);
  configurator.SetDefectReward(3);
}
}