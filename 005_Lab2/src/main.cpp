#include <iostream>
#include <ranges>
#include <algorithm>
#include <fstream>
#include "Game/Game.h"
#include "Configurator.h"

void EjectNamesFromArguments(std::vector<std::string>& arguments) {
  auto is_name = [](std::string& s) { return !s.starts_with("--"); };

  auto name_view = std::ranges::views::filter(arguments, is_name);
  auto names = std::vector<std::string>(name_view.begin(),
                                        name_view.end());

  PrisonerSimulator::Configurator::Instance().SetStrategyNames(std::move(names));
}

void EjectModeFromArguments(std::vector<std::string>& arguments) {
  auto is_mode = [](std::string& s) { return s.starts_with("--mode="); };

  auto mode_view = std::ranges::views::filter(arguments, is_mode);
  auto mode = mode_view.begin()->substr(7);

  PrisonerSimulator::Configurator::Instance().SetModeName(std::move(mode));
}

void EjectStepsFromArguments(std::vector<std::string>& arguments) {
  auto is_steps = [](std::string& s) { return s.starts_with("--steps="); };

  auto steps_view = std::ranges::views::filter(arguments, is_steps);
  if (steps_view.empty())
    return;

  int steps = std::stoi(steps_view.begin()->substr(8));

  PrisonerSimulator::Configurator::Instance().SetRoundsCount(steps);
}

void EjectMatrixPathFromArguments(std::vector<std::string>& arguments) {
  auto is_matrix = [](std::string& s) { return s.starts_with("--matrix="); };

  auto matrix_view = std::ranges::views::filter(arguments, is_matrix);
  if (matrix_view.empty())
    return;

  auto path = matrix_view.begin()->substr(9);

  std::ifstream stream(path);
  int cooperation_reward, cooperation_fine, defect_reward, defect_fine;
  stream >> cooperation_reward >> cooperation_fine >> defect_reward >> defect_fine;
  stream.close();

  PrisonerSimulator::Configurator::Instance().SetCooperationReward(cooperation_reward);
  PrisonerSimulator::Configurator::Instance().SetCooperationFine(cooperation_fine);
  PrisonerSimulator::Configurator::Instance().SetDefectReward(defect_reward);
  PrisonerSimulator::Configurator::Instance().SetDefectFine(defect_fine);
}

int main(int argc, char* argv[]) {
  int const min_arguments_count = 4;
  if (argc < min_arguments_count) {
    std::cout << "Not enough arguments" << std::endl;
    return 1;
  }

  std::vector<std::string> arguments(argc - 1);
  for (int i = 1; i < argc; ++i)  // Skip exec path
    arguments[i - 1] = argv[i];

  try {
    EjectNamesFromArguments(arguments);
    EjectModeFromArguments(arguments);
    EjectStepsFromArguments(arguments);
    EjectMatrixPathFromArguments(arguments);
  }
  catch (std::exception& exception) {
    std::cout << "Getting input failed: " << exception.what();
    return 2;
  }

  PrisonerSimulator::Game game;

  try {
    game.Run();
  }
  catch (std::exception& exception) {
    std::cout << "Exception. End of simulation. Details: " << exception.what();
    return 3;
  }

  return 0;
}
