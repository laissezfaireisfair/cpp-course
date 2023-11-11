#pragma once

#include <vector>
#include <memory>

#include "Audio.h"
#include "IAudioPoolFacade.h"
#include "Commands/ICommand.h"
#include "AppParameters.h"

namespace audioConverter {
template<class T> using sptr = std::shared_ptr<T>;

class Application : public IAudioPoolFacade {
 public:
  explicit Application(AppParameters& parameters);

  void Run();

  bool IsInPoolRange(size_t index) override;

  wptr<Audio> index(size_t index) override;

 private:
  std::vector<sptr<Audio>> audio_pool_;

  std::vector<ICommand> commands_;

  std::weak_ptr<Audio> audio_to_modify_;
};
}