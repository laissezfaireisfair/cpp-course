#include <charconv>

#include "Commands/MixCommandFactory.h"
#include "Commands/MixCommand.h"

namespace audioConverter {

MixCommandFactory::MixCommandFactory(IAudioPoolFacade* audio_pool_facade) :
    ICommandFactory(audio_pool_facade) {
}

std::unique_ptr<ICommand> MixCommandFactory::CreateCommand(std::vector<std::string>& parameters) {
  if (parameters.size() != 3)
    throw std::invalid_argument("MixCommandFactory::CreateCommand(): Two parameters expected");

  int mix_after_sec = 0;
  std::from_chars(parameters[2].data(), parameters[2].data() + parameters[2].size(), mix_after_sec);

  std::weak_ptr<Audio> audio_to_mix_with = GetAudioFromPoolByAlias(parameters[1]);

  return std::make_unique<MixCommand>(mix_after_sec, audio_to_mix_with);
}

MixCommandFactory::~MixCommandFactory() = default;
}