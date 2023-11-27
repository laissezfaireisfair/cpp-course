#include <charconv>

#include "Commands/InsertCommandFactory.h"
#include "Commands/InsertCommand.h"

namespace audioConverter {

InsertCommandFactory::InsertCommandFactory(IAudioPoolFacade* audio_pool_facade) :
    ICommandFactory(audio_pool_facade) {
}

std::unique_ptr<ICommand> InsertCommandFactory::CreateCommand(std::vector<std::string>& parameters) {
  if (parameters.size() != 3)
    throw std::invalid_argument("InsertCommandFactory::CreateCommand(): Two parameters expected");

  int insert_after_sec = 0;
  std::from_chars(parameters[2].data(), parameters[2].data() + parameters[2].size(), insert_after_sec);

  std::weak_ptr<Audio> audio_to_insert = GetAudioFromPoolByAlias(parameters[1]);

  return std::make_unique<InsertCommand>(insert_after_sec, audio_to_insert);
}

InsertCommandFactory::~InsertCommandFactory() = default;
}