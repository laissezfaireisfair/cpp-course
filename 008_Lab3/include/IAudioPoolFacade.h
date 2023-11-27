#pragma once
#include <memory>
#include "Audio.h"

namespace audioConverter {
using std::weak_ptr;

class IAudioPoolFacade {
 public:
  virtual bool IsAudioIndexCorrect(size_t index) = 0;

  virtual weak_ptr<Audio> GetAudioByIndex(size_t index) = 0;

  virtual ~IAudioPoolFacade();
};
}