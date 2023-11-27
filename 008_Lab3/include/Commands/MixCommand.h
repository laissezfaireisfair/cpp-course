#pragma once

#include "ICommand.h"

namespace audioConverter {
class MixCommand : public ICommand {
 public:
  MixCommand(int mix_after_sec, std::weak_ptr<Audio>& audio_to_mix_with);

  void Run(std::weak_ptr<Audio>& audio_to_modify) override;

  ~MixCommand() override;

 private:
  int mix_after_sec_;

  std::weak_ptr<Audio> audio_to_mix_with_;
};
}