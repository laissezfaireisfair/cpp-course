#pragma once

#include "INotifier.h"

class EmailNotifier : public INotifier {
 public:
  explicit EmailNotifier(std::string && phone_number);

  explicit EmailNotifier(std::string const& phone_number);

  void Notify(std::string const& message) override;

 private:
  std::string email;
};