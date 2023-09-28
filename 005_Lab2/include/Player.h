#pragma once

#include <map>
#include <vector>
#include <memory>
#include "IPlayerStatusFacade.h"
#include "IPlayerPlayFacade.h"
#include "IStrategy.h"

namespace PrisonerSimulator {
template<class T> using uptr = std::unique_ptr<T>;

class Player : public IPlayerStatusFacade, public IPlayerPlayFacade {
  int id_;
  std::map<int, std::vector<Decision>> my_decisions_by_rival_id_;
  std::map<int, std::vector<Decision>> rival_decisions_by_id_;
  int score_;
  uptr<IStrategy> strategy_;

 public:
  Player(int id, uptr<IStrategy>&& strategy);

  Player(Player&& player) noexcept;

  ~Player() override;

  Decision MakeDecision(int rivalId) override;

  void StoreDecision(int rivalId, Decision decision) override;

  void UpdateScore(int delta) override;

  int GetId() override;

  int GetScore() override;

  const std::vector<Decision>& GetMyDecisionsByRivalId(int rivalId) override;

  const std::vector<Decision>& GetRivalDecisionsById(int rivalId) override;
};
}