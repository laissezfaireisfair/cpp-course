#pragma once

#include "ICommandFactory.h"

namespace audioConverter{
class MixCommandFactory : public ICommandFactory{
 public:
  explicit MixCommandFactory(wptr<vec<Audio>>& audio_pool_ref);

  uptr<ICommand> CreateCommand(vec<str>& parameters) override;

  ~MixCommandFactory() override;
};
}