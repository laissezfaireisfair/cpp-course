#include "gtest/gtest.h"
#include "TestUtils.h"
#include "Game/Game.h"

TEST(SimulationResultTestTournament, DefaultConstructor) {
  Tests::TestUtils::SetDefaultTournamentConfiguration(false);
  PrisonerSimulator::Game game;
  game.Run();
  auto& players = game.GetPlayers();
  EXPECT_EQ(players[0]->GetScore(), 60);
  EXPECT_EQ(players[1]->GetScore(), 46);
  EXPECT_EQ(players[2]->GetScore(), 10);
  EXPECT_EQ(players[3]->GetScore(), 24);
  EXPECT_EQ(players[4]->GetScore(), 24);
}

TEST(SimulationResultTestTDetailed, DefaultConstructor) {
  Tests::TestUtils::SetDefaultDetailedConfiguration();
  PrisonerSimulator::Game game;
  game.Run();
  auto& players = game.GetPlayers();
  EXPECT_EQ(players[0]->GetScore(), -8);
  EXPECT_EQ(players[1]->GetScore(), -20);
  EXPECT_EQ(players[2]->GetScore(), -26);
}

TEST(SimulationResultTestFast, DefaultConstructor) {
  Tests::TestUtils::SetDefaultFastConfiguration();
  PrisonerSimulator::Game game;
  game.Run();
  auto& players = game.GetPlayers();
  EXPECT_EQ(players[0]->GetScore(), -8);
  EXPECT_EQ(players[1]->GetScore(), -20);
  EXPECT_EQ(players[2]->GetScore(), -26);
}
