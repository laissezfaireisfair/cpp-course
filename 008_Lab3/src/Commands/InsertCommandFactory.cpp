#include <charconv>

#include "Commands/InsertCommandFactory.h"
#include "Commands/InsertCommand.h"

namespace audioConverter {
using std::invalid_argument;
using std::from_chars;

InsertCommandFactory::InsertCommandFactory(IAudioPoolFacade* audio_pool_facade) :
    ICommandFactory{audio_pool_facade} {
}

unique_ptr<ICommand> InsertCommandFactory::CreateCommand(vector<string>& parameters) {
  if (parameters.size() != 3)
    throw invalid_argument("InsertCommandFactory::CreateCommand(): Two parameters expected");

  int insert_after_sec = 0;
  from_chars(parameters[2].data(), parameters[2].data() + parameters[2].size(), insert_after_sec);

  weak_ptr<Audio> audio_to_insert = GetAudioFromPoolByAlias(parameters[1]);

  return make_unique<InsertCommand>(insert_after_sec, audio_to_insert);
}

InsertCommandFactory::~InsertCommandFactory() = default;
}