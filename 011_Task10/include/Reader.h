#pragma once

#include "Document.h"

namespace ini {
using std::istream;

class Reader {
 public:
  Reader();

  Document ReadDocument(istream& stream);

  ~Reader();

 private:
  class Impl;
  unique_ptr<Impl> pimpl_;
};
}
