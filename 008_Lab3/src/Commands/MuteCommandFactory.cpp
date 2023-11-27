#include <stdexcept>
#include <charconv>

#include "Commands/MuteCommandFactory.h"
#include "Commands/MuteCommand.h"

namespace audioConverter {

MuteCommandFactory::MuteCommandFactory(IAudioPoolFacade* audio_pool_facade) : ICommandFactory(
    audio_pool_facade) {
}

std::unique_ptr<ICommand> MuteCommandFactory::CreateCommand(std::vector<std::string>& parameters) {
  if (parameters.size() != 3)
    throw std::invalid_argument("MuteCommandFactory::CreateCommand(): Two parameters expected");

  int mute_from_sec = 0;
  std::from_chars(parameters[1].data(), parameters[1].data() + parameters[1].size(), mute_from_sec);

  int mute_to_sec = 0;
  std::from_chars(parameters[2].data(), parameters[2].data() + parameters[2].size(), mute_to_sec);

  return std::make_unique<MuteCommand>(mute_from_sec, mute_to_sec);
}

MuteCommandFactory::~MuteCommandFactory() = default;
}