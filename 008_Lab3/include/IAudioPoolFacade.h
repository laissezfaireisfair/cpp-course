#pragma once
#include <memory>
#include "Audio.h"

namespace audioConverter {
template<class T> using wptr = std::weak_ptr<T>;

class IAudioPoolFacade {
 public:
  virtual bool IsAudioIndexCorrect(size_t index) = 0;

  virtual wptr<Audio> GetAudioByIndex(size_t index) = 0;

  virtual ~IAudioPoolFacade();
};
}