#pragma once

#include "Workers/Filter.h"

namespace task11{
using std::istream;
using std::ostream;

class PipelineBuilder {
 public:
  explicit PipelineBuilder(istream& in);

  PipelineBuilder& FilterBy(Filter::Predicate predicate);

  PipelineBuilder& CopyTo(string recipient);

  PipelineBuilder& Send(ostream& out);

  unique_ptr<Worker> Build();

  ~PipelineBuilder();

 private:
  class Impl;
  unique_ptr<Impl> pimpl_;
};
}