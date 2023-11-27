#pragma once

#include "ICommand.h"

namespace audioConverter {
using std::unique_ptr;
class MixCommand : public ICommand {
 public:
  MixCommand(int mix_after_sec, weak_ptr<Audio>& audio_to_mix_with);

  void Run(weak_ptr<Audio>& audio_to_modify) override;

  ~MixCommand() override;

 private:
  class Impl;
  unique_ptr<Impl> pimpl_;
};
}