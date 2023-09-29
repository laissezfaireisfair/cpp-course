#include <stdexcept>

#include "PlayerFactory.h"
#include "KindRepeaterStrategy.h"

namespace PrisonerSimulator {
PlayerFactory::PlayerFactory() : id_counter_(0) {
}

PlayerFactory::~PlayerFactory() = default;

uptr<Player> PlayerFactory::CreatePlayer(std::string const& strategyName) {
  uptr<KindRepeaterStrategy> strategy;
  if (strategyName == "KindRepeaterStrategy")
    strategy = std::make_unique<KindRepeaterStrategy>();
  else
    throw std::invalid_argument("Bad strategy name: " + strategyName);

  int id = id_counter_++;
  auto name = strategyName + std::to_string(id);

  auto player = std::make_unique<Player>(id, std::move(name), std::move(strategy));
  return player;
}
}