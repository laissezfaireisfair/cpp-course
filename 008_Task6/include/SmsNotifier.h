#pragma once

#include "INotifier.h"

class SmsNotifier : public INotifier {
 public:
  explicit SmsNotifier(std::string && phone_number);

  explicit SmsNotifier(std::string const& phone_number);

  void Notify(std::string const& message) override;

 private:
  std::string phone_number_;
};