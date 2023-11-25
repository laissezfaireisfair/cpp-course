#include "Commands/MuteCommand.h"

namespace audioConverter {

MuteCommand::MuteCommand(int mute_from_sec, int mute_to_sec) :
    mute_from_sec_(mute_from_sec),
    mute_to_sec_(mute_to_sec) {
}

void MuteCommand::Run(wptr<Audio>& audio_to_modify) {
  auto& to_modify = *audio_to_modify.lock();

  size_t mute_from_sample = mute_from_sec_ * to_modify.kSamples_per_second_;
  size_t mute_to_sample = mute_to_sec_ * to_modify.kSamples_per_second_;
  for (size_t i = mute_from_sample; i < to_modify.SamplesCount() && i < mute_to_sample; ++i)
    to_modify[mute_from_sample + i] = 0;
}

MuteCommand::~MuteCommand() = default;
}