#pragma once

#include <map>
#include <vector>
#include <memory>
#include "IPlayerStrategyFacade.h"
#include "IPlayerPlayFacade.h"
#include "Player/Strategies/IStrategy.h"

namespace PrisonerSimulator {
template<class T> using uptr = std::unique_ptr<T>;

class Player : public IPlayerStrategyFacade, public IPlayerPlayFacade {
  int id_;
  std::string name_;
  std::map<int, std::vector<Decision>> my_decisions_by_rival_id_;
  std::map<int, std::vector<Decision>> rival_decisions_by_id_;
  std::map<int, int> last_delta_by_id;
  int score_;
  uptr<IStrategy> strategy_;

 public:
  Player(int id, std::string&& name, uptr<IStrategy>&& strategy);

  Player(Player&& player) noexcept;

  ~Player() override;

  Decision MakeDecision(int rivalId) override;

  void StoreDecision(int rivalId, Decision decision) override;

  void UpdateScore(int delta, int rivalId) override;

  int GetId() override;

  int GetScore() override;

  int GetLastDelta(int rivalId) override;

  const std::vector<Decision>& GetMyDecisionsByRivalId(int rivalId) override;

  const std::vector<Decision>& GetRivalDecisionsById(int rivalId) override;

  std::string GetName() override;

  Decision GetLastDecision(int rivalId) override;
};
}