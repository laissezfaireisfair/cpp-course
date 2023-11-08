#include "Commands/ICommandFactory.h"

namespace audioConverter {

ICommandFactory::ICommandFactory(wptr<vec<Audio>>& audio_pool_ref) {
  audio_pool_ref_ = audio_pool_ref;
}

ICommandFactory::~ICommandFactory() = default;
}