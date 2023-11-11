#include <charconv>

#include "Commands/InsertCommandFactory.h"
#include "Commands/InsertCommand.h"

namespace audioConverter {

InsertCommandFactory::InsertCommandFactory(const wptr<IAudioPoolFacade>& audio_pool_facade) :
    ICommandFactory(audio_pool_facade) {
}

uptr<ICommand> InsertCommandFactory::CreateCommand(vec<str>& parameters) {
  if (parameters.size() != 2)
    throw std::invalid_argument("InsertCommandFactory::CreateCommand(): Two parameters expected");

  int insert_after_sec = 0;
  std::from_chars(parameters[0].data(), parameters[0].data() + parameters[0].size(), insert_after_sec);

  wptr<Audio> audio_to_insert = GetAudioFromPoolByAlias(parameters[1]);

  return std::make_unique<InsertCommand>(insert_after_sec, audio_to_insert);
}

InsertCommandFactory::~InsertCommandFactory() = default;
}