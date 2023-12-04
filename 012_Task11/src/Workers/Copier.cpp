#include "Workers/Copier.h"

namespace task11 {
using std::make_unique;

Copier::Copier(string receiver) :
    receiver_{std::move(receiver)} {
}

Copier::~Copier() = default;

void Copier::Process(unique_ptr<Email> email) {
  if (email->To() != receiver_){
    auto copy = make_unique<Email>(*email, receiver_);
    PassOn(std::move(copy));
  }

  PassOn(std::move(email));
}
}