#include "gtest/gtest.h"
#include "Game/Game.h"

TEST(CreationTest, DefaultConstructor) {
EXPECT_NO_THROW({
PrisonerSimulator::Game game;
});
}