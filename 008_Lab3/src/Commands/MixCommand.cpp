#include "Commands/MixCommand.h"

namespace audioConverter {

MixCommand::MixCommand(int mix_after_sec, wptr<Audio>& audio_to_mix_with) :
    mix_after_sec_(mix_after_sec),
    audio_to_mix_with_(audio_to_mix_with) {
}

void MixCommand::Run(wptr<Audio>& audio_to_modify) {
  auto& to_modify = *audio_to_modify.lock();
  auto& to_mix = *audio_to_mix_with_.lock();

  size_t insert_after_sample = mix_after_sec_ * to_modify.kSamples_per_second_;

  size_t end_of_new_block = insert_after_sample + to_mix.SamplesCount();

  if (end_of_new_block > to_modify.SamplesCount())
    to_modify.Extend(end_of_new_block + 1);

  for (size_t i = 0; i < to_mix.SamplesCount(); ++i)
    to_modify[insert_after_sample + i] = int16_t((to_modify[insert_after_sample + i] + to_mix[i]) / 2);
}

MixCommand::~MixCommand() = default;
}