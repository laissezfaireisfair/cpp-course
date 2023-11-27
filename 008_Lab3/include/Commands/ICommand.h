#pragma once

#include <memory>

#include "Audio.h"

namespace audioConverter {
class ICommand {
 public:
  ICommand();

  virtual void Run(std::weak_ptr<Audio>& audio_to_modify) = 0;

  virtual ~ICommand();
};
}