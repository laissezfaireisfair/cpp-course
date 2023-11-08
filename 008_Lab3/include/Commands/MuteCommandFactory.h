#pragma once

#include "ICommandFactory.h"

namespace audioConverter{
class MuteCommandFactory : public ICommandFactory{
 public:
  explicit MuteCommandFactory(wptr<vec<Audio>>& audio_pool_ref);

  uptr<ICommand> CreateCommand(vec<str>& parameters) override;

  ~MuteCommandFactory() override;
};
}