#pragma once

#include "Worker.h"

namespace task11{
using std::istream;

class Reader : public Worker {
 public:
  explicit Reader(istream& stream);

  ~Reader() override;

  void Process(unique_ptr<Email> email) override;

  void Run() override;

 private:
  istream& stream_;
};
}