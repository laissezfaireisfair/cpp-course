#pragma once

#include "ICommandFactory.h"

namespace audioConverter {
class MixCommandFactory : public ICommandFactory {
 public:
  explicit MixCommandFactory(IAudioPoolFacade* audio_pool_facade);

  uptr<ICommand> CreateCommand(vec<str>& parameters) override;

  ~MixCommandFactory() override;
};
}