#pragma once

#include <string>

#include "Player.h"

namespace PrisonerSimulator {
class PlayerFactory {
  int id_counter_;

 public:
  PlayerFactory();

  ~PlayerFactory();

  uptr<Player> CreatePlayer(std::string& strategy);
};
}
