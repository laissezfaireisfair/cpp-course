#pragma once

#include "Document.h"

namespace ini {
using std::ostream;

class Writer {
 public:
  void static WriteDocument(Document const& document, ostream& stream);

 private:
  class Impl;
};
}
