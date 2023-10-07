#include "gtest/gtest.h"
#include "TestUtils.h"
#include "Game/Game.h"

TEST(GameRunTestTournament, DefaultConstructor) {
  EXPECT_NO_THROW({
                    Tests::TestUtils::SetDefaultTournamentConfiguration(true);
                    PrisonerSimulator::Game game;
                    game.Run();
                  });
}

TEST(GameRunTestDetailed, DefaultConstructor) {
  EXPECT_NO_THROW({
                    Tests::TestUtils::SetDefaultDetailedConfiguration();
                    PrisonerSimulator::Game game;
                    game.Run();
                  });
}

TEST(GameRunTestFast, DefaultConstructor) {
  EXPECT_NO_THROW({
                    Tests::TestUtils::SetDefaultFastConfiguration();
                    PrisonerSimulator::Game game;
                    game.Run();
                  });
}
