#include "Commands/MixCommand.h"

namespace audioConverter {

MixCommand::MixCommand(int mix_after_sec, wptr<Audio> & audio_to_mix_with) {
  mix_after_sec_ = mix_after_sec;
  audio_to_mix_with_ = audio_to_mix_with;
}

void MixCommand::Run(Audio& audio_to_modify) {
  // TODO: Implement
}

MixCommand::~MixCommand() = default;
}