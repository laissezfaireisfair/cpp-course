#pragma once

#include "ICommandFactory.h"

namespace audioConverter {
class InsertCommandFactory : public ICommandFactory {
 public:
  explicit InsertCommandFactory(IAudioPoolFacade* audio_pool_facade);

  std::unique_ptr<ICommand> CreateCommand(std::vector<std::string>& parameters) override;

  ~InsertCommandFactory() override;
};
}