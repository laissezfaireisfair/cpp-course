#pragma once

#include "ICommand.h"

namespace audioConverter {
class MuteCommand : public ICommand {
 public:
  MuteCommand(int mute_from_sec, int mute_to_sec);

  void Run(wptr<Audio>& audio_to_modify) override;

  ~MuteCommand() override;

 private:
  int mute_from_sec_;

  int mute_to_sec_;
};
}