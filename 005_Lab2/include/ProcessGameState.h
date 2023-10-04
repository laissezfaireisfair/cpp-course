#pragma once

#include <vector>
#include "IGameState.h"
#include "IPlayerPlayFacade.h"

namespace PrisonerSimulator {
template<class T> using wptr = std::weak_ptr<T>;

/// Abstract class that implements basic competition step
class ProcessGameState : public IGameState {
 protected:
  std::vector<wptr<IPlayerPlayFacade>> current_rivals_;
  size_t player_idx_;
  size_t rival_idx_;

  // Returns true if each one have finished a round with each one
  bool RunCompetitionStep();
 public:
  explicit ProcessGameState(Game* game);
};
}