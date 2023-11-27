#pragma once

#include "ICommand.h"

namespace audioConverter {
using std::unique_ptr;

class MuteCommand : public ICommand {
 public:
  MuteCommand(int mute_from_sec, int mute_to_sec);

  void Run(weak_ptr<Audio>& audio_to_modify) override;

  string Description() override;

  ~MuteCommand() override;

 private:
  class Impl;
  unique_ptr<Impl> pimpl_;
};
}