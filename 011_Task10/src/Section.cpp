#include <unordered_map>

#include "Section.h"

namespace ini {
using std::make_unique;
using std::unordered_map;

class Section::Impl {
 public:
  explicit Impl(string name) :
      name{std::move(name)},
      value_by_key_{} {
  }

  Impl(string name, vector<pair<string, string>> const& keys_and_values) :
      Impl{std::move(name)} {
    for (auto& pair : keys_and_values)
      value_by_key_[pair.first] = pair.second;
  }

  string const& GetName() const {
    return name;
  }

  string const& GetValueByKey(string const& key) const {
    return value_by_key_.at(key);
  }

  void SetValueByKey(string key, string value) {
    value_by_key_[std::move(key)] = std::move(value);
  }

  vector<pair<string const*, string const *>> GetEntries(){
    vector<pair<string const*, string const *>> entries;
    for (auto& pair : value_by_key_)
      entries.emplace_back(&pair.first, &pair.second);
    return entries;
  }

 private:
  string name;

  unordered_map<string, string> value_by_key_;
};

Section::Section(string name) :
    pimpl_{make_unique<Impl>(std::move(name))} {
}

Section::Section(Section&& section) noexcept = default;

Section::Section(string name, vector<pair<string, string>> const& keys_and_values) :
    pimpl_{make_unique<Impl>(std::move(name), keys_and_values)} {
}

string const& Section::GetValueByKey(const string& key) const {
  return pimpl_->GetValueByKey(key);
}

void Section::SetValueByKey(string key, string value) {
  pimpl_->SetValueByKey(std::move(key), std::move(value));
}

vector<pair<string const*, string const *>> Section::GetEntries() const {
  return pimpl_->GetEntries();
}
string const& Section::GetName() const {
  return pimpl_->GetName();
}

Section& Section::operator=(Section&& section) noexcept {
  this->pimpl_ = std::move(section.pimpl_);
  return *this;
}

Section::~Section() = default;
}