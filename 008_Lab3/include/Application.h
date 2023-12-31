#pragma once

#include <memory>

#include "Audio.h"
#include "IAudioPoolFacade.h"
#include "AppParameters.h"

namespace audioConverter {
using std::unique_ptr;

class Application : public IAudioPoolFacade {
 public:
  explicit Application(AppParameters& parameters);

  void Run();

  bool IsAudioIndexCorrect(size_t index) override;

  weak_ptr<Audio> GetAudioByIndex(size_t index) override;

  ~Application() override;

 private:
  class Impl;
  unique_ptr<Impl> pimpl_;
};
}