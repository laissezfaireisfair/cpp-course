#pragma once

#include <memory>

#include "Audio.h"

namespace audioConverter {
template<class T> using wptr = std::weak_ptr<T>;

class ICommand {
 public:
  ICommand();

  virtual void Run(wptr<Audio>& audio_to_modify) = 0;

  virtual ~ICommand();
};
}