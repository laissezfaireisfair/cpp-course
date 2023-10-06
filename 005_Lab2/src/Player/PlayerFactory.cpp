#include <stdexcept>

#include "Player/PlayerFactory.h"
#include "Player/Strategies/KindRepeaterStrategy.h"
#include "Player/Strategies/EvilRepeaterStrategy.h"
#include "Player/Strategies/KindDumbassStrategy.h"
#include "Player/Strategies/EvilDumbassStrategy.h"
#include "Player/Strategies/RandomStrategy.h"
#include "Player/Strategies/KindForgivingRepeaterStrategy.h"
#include "Player/Strategies/InconsistentStrategy.h"

namespace PrisonerSimulator {
PlayerFactory::PlayerFactory() : id_counter_(0) {
}

PlayerFactory::~PlayerFactory() = default;

uptr<Player> PlayerFactory::CreatePlayer(std::string const& strategyName) {
  uptr<IStrategy> strategy;

  if (strategyName == "KindRepeaterStrategy")
    strategy = std::make_unique<KindRepeaterStrategy>();

  else if (strategyName == "EvilRepeaterStrategy")
    strategy = std::make_unique<EvilRepeaterStrategy>();

  else if (strategyName == "KindDumbassStrategy")
    strategy = std::make_unique<KindDumbassStrategy>();

  else if (strategyName == "EvilDumbassStrategy")
    strategy = std::make_unique<EvilDumbassStrategy>();

  else if (strategyName == "RandomStrategy")
    strategy = std::make_unique<RandomStrategy>();

  else if (strategyName == "KindForgivingRepeaterStrategy")
    strategy = std::make_unique<KindForgivingRepeaterStrategy>();

  else if (strategyName == "InconsistentStrategy")
    strategy = std::make_unique<InconsistentStrategy>();

  else
    throw std::invalid_argument("Bad strategy name: " + strategyName);

  int id = id_counter_++;
  auto name = strategyName + std::to_string(id);

  auto player = std::make_unique<Player>(id, std::move(name), std::move(strategy));
  return player;
}
}