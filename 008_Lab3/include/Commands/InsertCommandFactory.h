#pragma once

#include "ICommandFactory.h"

namespace audioConverter {
class InsertCommandFactory : public ICommandFactory {
 public:
  explicit InsertCommandFactory(IAudioPoolFacade* audio_pool_facade);

  unique_ptr<ICommand> CreateCommand(vector<string>& parameters) override;

  ~InsertCommandFactory() override;
};
}