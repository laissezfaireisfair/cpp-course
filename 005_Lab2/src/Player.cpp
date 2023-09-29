#include <Player.h>

namespace PrisonerSimulator {
Player::Player(int id, std::string&& name, uptr<IStrategy>&& strategy) :
    id_(id),
    name_(std::move(name)),
    score_(0),
    my_decisions_by_rival_id_(std::map<int, std::vector<Decision>>()),
    rival_decisions_by_id_(std::map<int, std::vector<Decision>>()),
    strategy_(std::move(strategy)) {
}

Player::Player(Player&& player) noexcept = default;

Player::~Player() = default;

Decision Player::MakeDecision(int rivalId) {
  auto playerStatus = static_cast<IPlayerStrategyFacade*>(this);
  auto decision = strategy_->MakeDecision(playerStatus, rivalId);

  if (my_decisions_by_rival_id_.contains(rivalId))
    my_decisions_by_rival_id_[rivalId].push_back(decision);
  else
    my_decisions_by_rival_id_[rivalId] = std::vector<Decision>{decision};

  return decision;
}

void Player::StoreDecision(int rivalId, PrisonerSimulator::Decision decision) {
  if (rival_decisions_by_id_.contains(rivalId))
    rival_decisions_by_id_[rivalId].push_back(decision);
  else
    rival_decisions_by_id_[rivalId] = std::vector<Decision>{decision};
}

void Player::UpdateScore(int delta) {
  score_ += delta;
}

int Player::GetId() {
  return id_;
}

int Player::GetScore() {
  return score_;
}

const std::vector<Decision>& Player::GetMyDecisionsByRivalId(int rivalId) {
  if (!my_decisions_by_rival_id_.contains(rivalId))
    my_decisions_by_rival_id_[rivalId] = std::vector<Decision>{};

  return my_decisions_by_rival_id_[rivalId];
}

const std::vector<Decision>& Player::GetRivalDecisionsById(int rivalId) {
  if (!rival_decisions_by_id_.contains(rivalId))
    rival_decisions_by_id_[rivalId] = std::vector<Decision>{};

  return rival_decisions_by_id_[rivalId];
}

std::string Player::GetName() {
  return name_;
}

Decision Player::LastDecision(int rivalId) {
  return my_decisions_by_rival_id_[rivalId].back();
}
}