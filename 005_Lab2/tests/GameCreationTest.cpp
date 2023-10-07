#include "gtest/gtest.h"
#include "TestUtils.h"
#include "Game/Game.h"

TEST(CreationTest, DefaultConstructor) {
  EXPECT_NO_THROW({
                    Tests::TestUtils::SetDefaultTournamentConfiguration(true);
                    PrisonerSimulator::Game game;
                  });
}