#include "PipelineBuilder.h"

#include <utility>
#include "Workers/Reader.h"
#include "Workers/Copier.h"
#include "Workers/Sender.h"
#include "Workers/Filter.h"

namespace task11 {
using std::make_unique;

class PipelineBuilder::Impl {
 public:
  explicit Impl(istream& in) : first_{new Reader(in)} {
    last_ = first_;
  }

  void FilterBy(Filter::Predicate predicate)
  {
    Worker* filter = new Filter(std::move(predicate));  // Not great actually to have a copy of unique ptr

    last_->SetNext(unique_ptr<Worker>(filter));
    last_ = filter;
  }

  void CopyTo(string recipient)
  {
    Worker* copier = new Copier(std::move(recipient));

    last_->SetNext(unique_ptr<Worker>(copier));
    last_ = copier;
  }

  void Send(ostream& out)
  {
    Worker* sender = new Sender(out);

    last_->SetNext(unique_ptr<Worker>(sender));
    last_ = sender;
  }

  unique_ptr<Worker> Build() {
    unique_ptr<Worker> ptr(first_);

    first_ = nullptr;
    last_ = nullptr;

    return ptr;
  }

  ~Impl() = default;

 private:
  Worker* first_;
  Worker* last_;
};

PipelineBuilder::PipelineBuilder(istream& in) :
    pimpl_{make_unique<Impl>(in)} {
}

PipelineBuilder& PipelineBuilder::FilterBy(Filter::Predicate predicate) {
  pimpl_->FilterBy(std::move(predicate));
  return *this;
}

PipelineBuilder& PipelineBuilder::CopyTo(string recipient) {
  pimpl_->CopyTo(std::move(recipient));
  return *this;
}

PipelineBuilder& PipelineBuilder::Send(ostream& out) {
  pimpl_->Send(out);
  return *this;
}

unique_ptr<Worker> PipelineBuilder::Build() {
  return pimpl_->Build();
}

PipelineBuilder::~PipelineBuilder() = default;
}