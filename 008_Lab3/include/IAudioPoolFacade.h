#pragma once
#include <memory>
#include "Audio.h"

namespace audioConverter {


class IAudioPoolFacade {
 public:
  virtual bool IsAudioIndexCorrect(size_t index) = 0;

  virtual std::weak_ptr<Audio> GetAudioByIndex(size_t index) = 0;

  virtual ~IAudioPoolFacade();
};
}