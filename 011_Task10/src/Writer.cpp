#include "Writer.h"

namespace ini {
using std::endl;

class Writer::Impl {
 public:
  void static WriteDocument(Document const& document, ostream& stream) {
    auto sections = document.GetSections();

    for (auto section : sections) {
      stream << "[" << section->GetName() << "]" << endl;
      for (auto pair : section->GetEntries())
        stream << *pair.first << "=" << *pair.second << endl;
      stream << endl;
    }
  }
};

void Writer::WriteDocument(Document const& document, ostream& stream) {
  Writer::Impl::WriteDocument(document, stream);
}
}