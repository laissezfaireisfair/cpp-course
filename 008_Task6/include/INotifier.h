#pragma once

#include <string>

class INotifier {
 public:
  virtual void Notify(std::string const& message) = 0;
};