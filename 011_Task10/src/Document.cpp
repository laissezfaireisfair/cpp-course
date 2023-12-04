#include <unordered_map>

#include "Document.h"

namespace ini {
using std::make_unique;
using std::unordered_map;

class Document::Impl {
 public:
  Impl() :
      section_by_name_{} {
  }

  Section& AddSection(string name) {
    Section section(name);
    auto res = section_by_name_.emplace(std::move(name), std::move(section));
    return res.first->second;
  }

  Section const& GetSection(string const& name) const {
    return section_by_name_.at(name);
  }

  vector<Section const *> GetSections() const {
    vector<Section const*> sections;
    for (auto& pair: section_by_name_)
      sections.push_back(&pair.second);
    return sections;
  }

  size_t SectionsCount() const {
    return section_by_name_.size();
  }

  ~Impl() = default;

 private:
  unordered_map<string, Section> section_by_name_;
};

Document::Document() :
    pimpl_{make_unique<Impl>()} {
}

Document::Document(Document&& document) noexcept = default;

Section& Document::AddSection(string name) {
  return pimpl_->AddSection(std::move(name));
}

Section const& Document::GetSection(string const& name) const {
  return pimpl_->GetSection(name);
}

vector<Section const*> Document::GetSections() const {
  return pimpl_->GetSections();
}

size_t Document::SectionsCount() const {
  return pimpl_->SectionsCount();
}

Document::~Document() = default;
}