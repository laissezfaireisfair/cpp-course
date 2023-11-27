#include <charconv>

#include "Commands/MixCommandFactory.h"
#include "Commands/MixCommand.h"

namespace audioConverter {
using std::invalid_argument;
using std::from_chars;

MixCommandFactory::MixCommandFactory(IAudioPoolFacade* audio_pool_facade) :
    ICommandFactory{audio_pool_facade} {
}

unique_ptr<ICommand> MixCommandFactory::CreateCommand(vector<string>& parameters) {
  if (parameters.size() != 3)
    throw invalid_argument("MixCommandFactory::CreateCommand(): Two parameters expected");

  int mix_after_sec = 0;
  from_chars(parameters[2].data(), parameters[2].data() + parameters[2].size(), mix_after_sec);

  weak_ptr<Audio> audio_to_mix_with = GetAudioFromPoolByAlias(parameters[1]);

  return make_unique<MixCommand>(mix_after_sec, audio_to_mix_with);
}

MixCommandFactory::~MixCommandFactory() = default;
}