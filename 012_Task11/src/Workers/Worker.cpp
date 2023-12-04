#include "Workers/Worker.h"

namespace task11 {
using std::make_unique;

class Worker::Impl {
 public:
  Impl() :
      next_{} {
  }

  ~Impl() = default;

  void SetNext(unique_ptr<Worker> next) {
    next_ = std::move(next);
  }

  void PassOn(unique_ptr<Email> email) const {
    if (next_)
      next_->Process(std::move(email));
  }

  static void Run() {
    throw logic_error("This worker does not implement Run()");
  }

 private:
  unique_ptr<Worker> next_;
};

Worker::Worker() :
    pimpl_{make_unique<Impl>()} {
}

Worker::~Worker() = default;

void Worker::SetNext(unique_ptr<Worker> next) {
  pimpl_->SetNext(std::move(next));
}

void Worker::PassOn(unique_ptr<Email> email) const {
  pimpl_->PassOn(std::move(email));
}

void Worker::Run() {
  pimpl_->Run();
}
}