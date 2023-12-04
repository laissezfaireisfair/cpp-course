#pragma once

#include "Email.h"

namespace task11 {
using std::logic_error;

class Worker {
 public:
  Worker();

  virtual ~Worker();

  virtual void Process(unique_ptr<Email> email) = 0;

  void SetNext(unique_ptr<Worker> next);

  virtual void Run();

 protected:
  void PassOn(unique_ptr<Email> email) const;

 private:
  class Impl;
  unique_ptr<Impl> pimpl_;
};
}