#pragma once

#include <string>
#include <vector>
#include <memory>

#include "ICommand.h"
#include "IAudioPoolFacade.h"

namespace audioConverter {





class ICommandFactory {
 public:
  explicit ICommandFactory(IAudioPoolFacade* audio_pool_facade);

  virtual std::unique_ptr<ICommand> CreateCommand(std::vector<std::string>& parameters) = 0;

  virtual ~ICommandFactory();

 protected:
  IAudioPoolFacade* audio_pool_facade_;

  std::weak_ptr<Audio> GetAudioFromPoolByAlias(std::string const& alias);
};
}