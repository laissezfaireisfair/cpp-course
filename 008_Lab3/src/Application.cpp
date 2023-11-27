#include <sstream>
#include <map>

#include "Application.h"
#include "WavEncoder.h"
#include "Commands/ICommandFactory.h"
#include "Commands/MuteCommandFactory.h"
#include "Commands/MixCommandFactory.h"
#include "Commands/InsertCommandFactory.h"

namespace audioConverter {
class Application::Impl : public IAudioPoolFacade {
 public:
  explicit Impl(AppParameters& parameters) :
      audio_pool_{},
      commands_{},
      output_file_name{parameters.output_file_name} {
    for (auto& input_file_name : parameters.input_file_names) {
      std::ifstream stream(input_file_name);
      audio_pool_.push_back(WavEncoder::ReadAudio(stream));
      stream.close();
    }
    audio_to_modify_ = audio_pool_[0];

    std::ifstream config_stream(parameters.config_file_name);
    ReadCommands(config_stream);
    config_stream.close();
  }

  void Run() {
    for (auto& command : commands_)
      command->Run(audio_to_modify_);

    std::ofstream stream(output_file_name);
    WavEncoder::WriteAudio(stream, *audio_to_modify_.lock());
    stream.close();
  }

  bool IsAudioIndexCorrect(size_t index) override {
    return index < audio_pool_.size();
  }

  std::weak_ptr<Audio> GetAudioByIndex(size_t index) override {
    if (!IsAudioIndexCorrect(index))
      throw std::out_of_range("Index is out of audio pool range");

    return audio_pool_[index];
  }

  ~Impl() override = default;
 private:
  std::vector<std::shared_ptr<Audio>> audio_pool_;

  std::vector<std::unique_ptr<ICommand>> commands_;

  std::weak_ptr<Audio> audio_to_modify_;

  std::string output_file_name;

  void ReadCommands(std::ifstream& config_stream) {
    std::map<std::string, std::unique_ptr<ICommandFactory>> factoryByCommandName;
    factoryByCommandName["mute"] = std::make_unique<MuteCommandFactory>(this);
    factoryByCommandName["mix"] = std::make_unique<MixCommandFactory>(this);
    factoryByCommandName["insert"] = std::make_unique<InsertCommandFactory>(this);

    for (std::string line; getline(config_stream, line);) {
      auto tokens = Split(line);

      if (factoryByCommandName.contains(tokens[0]))
        commands_.push_back(factoryByCommandName[tokens[0]]->CreateCommand(tokens));
      else
        throw std::invalid_argument("Unknown command name");
    }
  }

  static std::vector<std::string> Split(std::string const& line) {
    std::stringstream line_stream(line);
    std::vector<std::string> tokens;
    for (std::string token; line_stream >> token;)
      tokens.push_back(token);
    return tokens;
  }
};

Application::Application(AppParameters& parameters) :
    pimpl{std::make_unique<Impl>(parameters)} {
}

void Application::Run() {
  pimpl->Run();
}

bool Application::IsAudioIndexCorrect(size_t index) {
  return pimpl->IsAudioIndexCorrect(index);
}

std::weak_ptr<Audio> Application::GetAudioByIndex(size_t index) {
  return pimpl->GetAudioByIndex(index);
}

Application::~Application() = default;
}