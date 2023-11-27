#pragma once

#include <memory>

#include "Audio.h"

namespace audioConverter {
using std::weak_ptr;

class ICommand {
 public:
  ICommand();

  virtual void Run(weak_ptr<Audio>& audio_to_modify) = 0;

  virtual ~ICommand();
};
}