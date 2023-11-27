#pragma once

#include "ICommandFactory.h"

namespace audioConverter {
class MuteCommandFactory : public ICommandFactory {
 public:
  explicit MuteCommandFactory(IAudioPoolFacade* audio_pool_facade);

  unique_ptr<ICommand> CreateCommand(vector<string>& parameters) override;

  ~MuteCommandFactory() override;
};
}