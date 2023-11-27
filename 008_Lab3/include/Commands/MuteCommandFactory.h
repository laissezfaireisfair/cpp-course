#pragma once

#include "ICommandFactory.h"

namespace audioConverter {
class MuteCommandFactory : public ICommandFactory {
 public:
  explicit MuteCommandFactory(IAudioPoolFacade* audio_pool_facade);

  std::unique_ptr<ICommand> CreateCommand(std::vector<std::string>& parameters) override;

  ~MuteCommandFactory() override;
};
}