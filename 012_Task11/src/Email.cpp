#include "Email.h"

namespace task11 {
using std::make_unique;

class Email::Impl {
 public:
  Impl() = delete;

  Impl(string from, string to, string body) :
      from_(std::move(from)),
      to_(std::move(to)),
      body_(std::move(body)) {
  }

  Impl(Impl&& other) noexcept = default;

  Impl(Impl const& other) = delete;

  ~Impl() = default;

  string const& From() const {
    return from_;
  }

  string const& To() const {
    return to_;
  }

  string const& Body() const {
    return body_;
  }

 private:
  string from_;

  string to_;

  string body_;
};

Email::Email(string from, string to, string body) :
    pimpl_{make_unique<Impl>(std::move(from), std::move(to), std::move(body))} {
}

Email::Email(Email&& other) noexcept = default;

Email::Email(const Email& copy, string receiver) :
    Email(copy.From(), std::move(receiver), copy.Body()) {
}

Email::~Email() = default;

string const& Email::From() const {
  return pimpl_->From();
}

string const& Email::To() const {
  return pimpl_->To();
}

string const& Email::Body() const {
  return pimpl_->Body();
}
}