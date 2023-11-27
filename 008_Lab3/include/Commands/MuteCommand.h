#pragma once

#include "ICommand.h"

namespace audioConverter {
class MuteCommand : public ICommand {
 public:
  MuteCommand(int mute_from_sec, int mute_to_sec);

  void Run(std::weak_ptr<Audio>& audio_to_modify) override;

  ~MuteCommand() override;

 private:
  class Impl;
  std::unique_ptr<Impl> pimpl_;
};
}