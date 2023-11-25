#pragma once

#include <vector>
#include <memory>

#include "Audio.h"
#include "IAudioPoolFacade.h"
#include "Commands/ICommand.h"
#include "AppParameters.h"

namespace audioConverter {
using std::string;
using std::vector;
using std::ifstream;

template<class T> using sptr = std::shared_ptr<T>;
template<class T> using wptr = std::weak_ptr<T>;
template<class T> using uptr = std::unique_ptr<T>;

class Application : public IAudioPoolFacade {
 public:
  explicit Application(AppParameters& parameters);

  void Run();

  bool IsAudioIndexCorrect(size_t index) override;

  wptr<Audio> GetAudioByIndex(size_t index) override;

 private:
  static sptr<Application> _instance;

  vector<sptr<Audio>> audio_pool_;

  vector<uptr<ICommand>> commands_;

  wptr<Audio> audio_to_modify_;

  string output_file_name;

  void ReadCommands(ifstream& config_stream);
};
}