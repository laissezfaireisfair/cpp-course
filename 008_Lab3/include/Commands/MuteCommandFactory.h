#pragma once

#include "ICommandFactory.h"

namespace audioConverter {
class MuteCommandFactory : public ICommandFactory {
 public:
  explicit MuteCommandFactory(const wptr<IAudioPoolFacade>& audio_pool_facade);

  uptr<ICommand> CreateCommand(vec<str>& parameters) override;

  ~MuteCommandFactory() override;
};
}