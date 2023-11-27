#pragma once

#include <string>
#include <vector>
#include <memory>

#include "ICommand.h"
#include "IAudioPoolFacade.h"

namespace audioConverter {
using std::unique_ptr;
using std::vector;
using std::string;

class ICommandFactory {
 public:
  explicit ICommandFactory(IAudioPoolFacade* audio_pool_facade);

  virtual unique_ptr<ICommand> CreateCommand(vector<string>& parameters) = 0;

  virtual ~ICommandFactory();

 protected:
  IAudioPoolFacade* audio_pool_facade_;

  weak_ptr<Audio> GetAudioFromPoolByAlias(string const& alias);
};
}