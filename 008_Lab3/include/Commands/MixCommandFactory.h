#pragma once

#include "ICommandFactory.h"

namespace audioConverter {
class MixCommandFactory : public ICommandFactory {
 public:
  explicit MixCommandFactory(IAudioPoolFacade* audio_pool_facade);

  std::unique_ptr<ICommand> CreateCommand(std::vector<std::string>& parameters) override;

  ~MixCommandFactory() override;
};
}