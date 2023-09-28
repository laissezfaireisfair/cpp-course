#include <stdexcept>

#include "PlayerFactory.h"
#include "KindRepeaterStrategy.h"

namespace PrisonerSimulator {
PlayerFactory::PlayerFactory() {
  id_counter_ = 0;
}

PlayerFactory::~PlayerFactory() = default;

uptr<Player> PlayerFactory::CreatePlayer(std::string& strategyName) {
  uptr<KindRepeaterStrategy> strategy;
  if (strategyName == "KindRepeaterStrategy")
    strategy = std::make_unique<KindRepeaterStrategy>();
  else
    throw std::invalid_argument("Bad strategy name: " + strategyName);

  auto player = std::make_unique<Player>(id_counter_++, std::move(strategy));
  return player;
}
}