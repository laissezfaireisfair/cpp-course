#include <iostream>
#include "EmailNotifier.h"

EmailNotifier::EmailNotifier(std::string&& phone_number) : email(phone_number) {
}

EmailNotifier::EmailNotifier(const std::string& phone_number) : email(phone_number) {
}

void EmailNotifier::Notify(const std::string& message) {
  std::cout << "Send " << message << " e-mail " << email << std::endl;
}
