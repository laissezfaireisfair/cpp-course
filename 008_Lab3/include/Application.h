#pragma once

#include <vector>
#include <memory>
#include "Audio.h"
namespace audioConverter {
class Application {
 public:
  explicit Application(AppParameters& parameters);

  void Run();

 private:
  std::vector<Audio> audio_pool_;

  std::vector<ICommand> commands_;

  std::weak_ptr<Audio> initial_audio_link_;
};
}