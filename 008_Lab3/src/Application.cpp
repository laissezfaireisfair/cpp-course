#include <sstream>
#include <map>
#include "Application.h"
#include "WavEncoder.h"
#include "Commands/ICommandFactory.h"
#include "Commands/MuteCommandFactory.h"
#include "Commands/MixCommandFactory.h"
#include "Commands/InsertCommandFactory.h"

namespace audioConverter {
using std::ofstream;
using std::out_of_range;
using std::getline;
using std::stringstream;

Application::Application(AppParameters& parameters) :
    audio_pool_{},
    commands_{},
    output_file_name{parameters.output_file_name} {
  for (auto& input_file_name : parameters.input_file_names) {
    ifstream stream(input_file_name);
    audio_pool_.push_back(WavEncoder::ReadAudio(stream));
    stream.close();
  }
  audio_to_modify_ = audio_pool_[0];

  ifstream config_stream(parameters.config_file_name);
  ReadCommands(config_stream);
  config_stream.close();
}

void Application::Run() {
  for (auto& command : commands_)
    command.Run(audio_to_modify_);

  ofstream stream(output_file_name);
  WavEncoder::WriteAudio(stream, *audio_to_modify_.lock());
  stream.close();
}

bool Application::IsAudioIndexCorrect(size_t index) {
  return index < audio_pool_.size();
}

wptr<Audio> Application::GetAudioByIndex(size_t index) {
  if (!IsAudioIndexCorrect(index))
    throw out_of_range("Index is out of audio pool range");

  return {audio_pool_[index]};
}

void Application::ReadCommands(ifstream& config_stream) {
  std::map<std::string, uptr<ICommandFactory>> factoryByCommandName;
  factoryByCommandName["mute"] = std::make_unique<MuteCommandFactory>(this);
  factoryByCommandName["mix"] = std::make_unique<MixCommandFactory>(this);
  factoryByCommandName["insert"] = std::make_unique<InsertCommandFactory>(this);

  for (string line; getline(config_stream, line); ) {
    stringstream line_stream(line);  // TODO: Eject to split()
    vector<string> tokens;
    for (string token; line_stream >> token; )
      tokens.push_back(token);

    if (factoryByCommandName.contains(tokens[0]))
      factoryByCommandName[tokens[0]]->CreateCommand(tokens);
    else
      throw std::invalid_argument("Unknown command name");
  }
}
}