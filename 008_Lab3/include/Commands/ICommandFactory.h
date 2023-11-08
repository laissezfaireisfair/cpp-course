#pragma once

#include <string>
#include <vector>
#include <memory>
#include "ICommand.h"

namespace audioConverter {
template<class T> using uptr = std::unique_ptr<T>;

using str = std::string;

class ICommandFactory {
 public:
  explicit ICommandFactory(wptr<vec<Audio>>& audio_pool_ref);

  virtual uptr<ICommand> CreateCommand(vec<str>& parameters) = 0;

  virtual ~ICommandFactory();

 protected:
  wptr<vec<Audio>> audio_pool_ref_;
};
}