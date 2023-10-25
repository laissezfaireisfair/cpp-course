#include <iostream>
#include "SmsNotifier.h"

SmsNotifier::SmsNotifier(std::string&& phone_number) : phone_number_(phone_number) {
}

SmsNotifier::SmsNotifier(const std::string& phone_number) : phone_number_(phone_number) {
}

void SmsNotifier::Notify(const std::string& message) {
  std::cout << "Send " << message << " to number " << phone_number_ << std::endl;
}
