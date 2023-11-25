#pragma once

#include "ICommandFactory.h"

namespace audioConverter {
class InsertCommandFactory : public ICommandFactory {
 public:
  explicit InsertCommandFactory(IAudioPoolFacade* audio_pool_facade);

  uptr<ICommand> CreateCommand(vec<str>& parameters) override;

  ~InsertCommandFactory() override;
};
}