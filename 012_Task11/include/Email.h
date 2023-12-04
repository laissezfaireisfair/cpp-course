#pragma once

#include <string>
#include <memory>

namespace task11 {
using std::string;
using std::unique_ptr;

class Email {
 public:
  Email() = delete;

  Email(string from, string to, string body);

  Email(Email&& other) noexcept;

  Email(Email const& other) = delete;

  Email(Email const& copy, string receiver);

  ~Email();

  string const& From() const;

  string const& To() const;

  string const& Body() const;

 private:
  class Impl;
  unique_ptr<Impl> pimpl_;
};
}