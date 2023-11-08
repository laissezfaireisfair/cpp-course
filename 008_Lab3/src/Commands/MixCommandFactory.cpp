#include <charconv>
#include "Commands/MixCommandFactory.h"
#include "Commands/MixCommand.h"

namespace audioConverter{

MixCommandFactory::MixCommandFactory(wptr<vec<Audio>>& audio_pool_ref) : ICommandFactory(audio_pool_ref) {
}

uptr<ICommand> MixCommandFactory::CreateCommand(vec<str>& parameters) {
  if (parameters.size() != 2)
    throw std::invalid_argument("MixCommandFactory::CreateCommand(): Two parameters expected");

  int mute_from_sec = 0;
  std::from_chars(parameters[0].data(), parameters[0].data() + parameters[0].size(), mute_from_sec);

  // TODO: Get audio by number in param

  return std::make_unique<MixCommand>(mix_after_sec, );
}

MixCommandFactory::~MixCommandFactory() =default;
}