#pragma once

#include <vector>
#include "GameRules.h"
#include "Player/IPlayerPlayFacade.h"
#include "Game/State/IGameState.h"

namespace PrisonerSimulator {
template<class T> using uptr = std::unique_ptr<T>;
template<class T> using sptr = std::shared_ptr<T>;

class Game {
  uptr<GameRules> game_rules_;
  std::vector<sptr<IPlayerPlayFacade>> players_;
  uptr<IGameState> game_state_;
 public:
  Game();

  ~Game();

  void SwitchGameState(uptr<IGameState> && game_state);

  void SetGameRules(uptr<GameRules> && game_rules);

  void AddPlayer(uptr<IPlayerPlayFacade> && player);

  std::vector<sptr<IPlayerPlayFacade>> & GetPlayers();

  uptr<GameRules>& GetGameRules();

  void Run();
};
}