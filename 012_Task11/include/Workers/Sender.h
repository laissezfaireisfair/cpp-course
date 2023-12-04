#pragma once

#include "Worker.h"

namespace task11{
using std::ostream;

class Sender : public Worker {
 public:
  explicit Sender(ostream& stream);

  ~Sender() override;

  void Process(unique_ptr<Email> email) override;

 private:
  ostream& stream_;
};
}