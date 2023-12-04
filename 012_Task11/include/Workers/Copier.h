#pragma once

#include "Worker.h"

namespace task11{
using std::string;

class Copier : public Worker {
 public:
  explicit Copier(string receiver);

  ~Copier() override;

  void Process(unique_ptr<Email> email) override;

 private:
  string receiver_;
};
}