#pragma once

#include "Section.h"

namespace ini {
using std::unique_ptr;

class Document {
 public:
  Document();

  Document(Document&& document) noexcept;

  Section& AddSection(string name);

  Section const& GetSection(string const& name) const;

  vector<Section const *> GetSections() const;

  size_t SectionsCount() const;

  ~Document();

 private:
  class Impl;
  unique_ptr<Impl> pimpl_;
};
}