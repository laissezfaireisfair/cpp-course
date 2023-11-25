#pragma once

#include <string>
#include <vector>
#include <memory>

#include "ICommand.h"
#include "IAudioPoolFacade.h"

namespace audioConverter {
template<class T> using uptr = std::unique_ptr<T>;
template<class T> using vec = std::vector<T>;

using str = std::string;

class ICommandFactory {
 public:
  explicit ICommandFactory(IAudioPoolFacade* audio_pool_facade);

  virtual uptr<ICommand> CreateCommand(vec<str>& parameters) = 0;

  virtual ~ICommandFactory();

 protected:
  IAudioPoolFacade* audio_pool_facade_;

  wptr<Audio> GetAudioFromPoolByAlias(str const& alias);
};
}