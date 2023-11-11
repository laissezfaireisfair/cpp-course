#include "Application.h"

namespace audioConverter {
Application::Application(AppParameters& parameters) {
  // TODO: Implement
}

void Application::Run() {
  for (auto& command : commands_)
    command.Run(audio_to_modify_);

  // TODO: Write modified audio back to drive
}

bool Application::IsInPoolRange(size_t index) {
  return index < audio_pool_.size();
}

wptr<Audio> Application::index(size_t index) {
  if (!IsInPoolRange(index))
    throw std::out_of_range("Index is out of audio pool range");

  return {audio_pool_[index]};
}
}