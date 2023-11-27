#pragma once

#include "ICommandFactory.h"

namespace audioConverter {
class MixCommandFactory : public ICommandFactory {
 public:
  explicit MixCommandFactory(IAudioPoolFacade* audio_pool_facade);

  unique_ptr<ICommand> CreateCommand(vector<string>& parameters) override;

  ~MixCommandFactory() override;
};
}