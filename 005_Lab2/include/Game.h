#pragma once

#include <vector>
#include "GameRules.h"
#include "IPlayerPlayFacade.h"
#include "IGameState.h"

namespace PrisonerSimulator {
template<class T> using uptr = std::unique_ptr<T>;

class Game {
  uptr<GameRules> game_rules_;
  std::vector<uptr<IPlayerPlayFacade>> players;
  uptr<IGameState> game_state_;
 public:
  Game();

  ~Game();

  void SwitchGameState(uptr<IGameState> && game_state);

  void SetGameRules(uptr<GameRules> && game_rules);

  void AddPlayer(uptr<IPlayerPlayFacade> && player);

  void Run();
};
}