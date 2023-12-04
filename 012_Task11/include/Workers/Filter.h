#pragma once

#include <functional>

#include "Worker.h"

namespace task11{

class Filter : public Worker {
 public:
  using Predicate = std::function<bool(const Email&)>;

  explicit Filter(Predicate predicate);

  ~Filter() override;

  void Process(unique_ptr<Email> email) override;

 private:
  Predicate predicate_;
};
}