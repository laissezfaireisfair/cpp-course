#pragma once

#include "ProcessGameState.h"

namespace PrisonerSimulator {
class TournamentGameState : public ProcessGameState {
  using PlayerPtr = std::weak_ptr<IPlayerPlayFacade>;
  int round;
  std::vector<std::vector<PlayerPtr>> waiting_groups_;

  void LoadNextPlayerGroup();

  void PrintGroupCompetitionResult();

 public:
  explicit TournamentGameState(Game* game);

  bool doStage() override;

  ~TournamentGameState() noexcept override;
};
}