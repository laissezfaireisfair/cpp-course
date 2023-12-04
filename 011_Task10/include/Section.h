#pragma once

#include <memory>
#include <string>
#include <vector>
#include <utility>

namespace ini {
using std::unique_ptr;
using std::string;
using std::vector;
using std::pair;

class Section {
 public:
  explicit Section(string name);

  Section(Section&& section) noexcept;

  Section(string name, vector<pair<string, string>> const& keys_and_values);

  string const& GetName() const;

  string const& GetValueByKey(string const& key) const;

  Section& operator=(Section && section) noexcept;

  void SetValueByKey(string key, string value);

  vector<pair<string const*, string const *>> GetEntries() const;

  ~Section();

 private:
  class Impl;
  unique_ptr<Impl> pimpl_;
};
}