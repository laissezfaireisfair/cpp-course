#include "Workers/Filter.h"

namespace task11 {

Filter::Filter(Filter::Predicate predicate) :
    predicate_{std::move(predicate)} {
}

Filter::~Filter() = default;

void Filter::Process(unique_ptr<Email> email) {
  if (predicate_(*email))
    PassOn(std::move(email));
}
}