#pragma once
#include "Audio.h"

namespace audioConverter {
class ICommand {
 public:
  virtual Audio Run() = 0;
};
}