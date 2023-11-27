#include <iostream>
#include <sstream>
#include <map>

#include "Application.h"
#include "WavEncoder.h"
#include "Commands/ICommandFactory.h"
#include "Commands/MuteCommandFactory.h"
#include "Commands/MixCommandFactory.h"
#include "Commands/InsertCommandFactory.h"

namespace audioConverter {
using std::ifstream;
using std::ofstream;
using std::out_of_range;
using std::map;
using std::make_unique;
using std::invalid_argument;
using std::stringstream;
using std::exception;
using std::cerr;
using std::endl;

class Application::Impl : public IAudioPoolFacade {
 public:
  explicit Impl(AppParameters& parameters) :
      audio_pool_{},
      commands_{},
      output_file_name{parameters.output_file_name} {
    for (auto& input_file_name : parameters.input_file_names) {
      try {
        ifstream stream(input_file_name);
        audio_pool_.push_back(WavEncoder::ReadAudio(stream, input_file_name));
        stream.close();
      }
      catch (exception& exception) {
        cerr << "Reading file " << input_file_name << " FAILED: " << endl << exception.what() << endl;
        throw;
      }
    }
    audio_to_modify_ = audio_pool_[0];

    try {
      ifstream config_stream(parameters.config_file_name);
      ReadCommands(config_stream);
      config_stream.close();
    }
    catch (exception& exception) {
      cerr << "Reading commands from " << parameters.config_file_name << " FAILED: " << endl << exception.what() << endl;
      throw;
    }
  }

  void Run() {
    for (auto& command : commands_) {
      try {
        command->Run(audio_to_modify_);
      }
      catch (exception& exception){
        cerr << "Command " << command->Description() << " execution FAILED: " << endl << exception.what() << endl;
        throw;
      }
    }

    try {
      ofstream stream(output_file_name);
      WavEncoder::WriteAudio(stream, *audio_to_modify_.lock());
      stream.close();
    }
    catch (exception& exception){
      cerr << "Writing output file to " << output_file_name << " FAILED: " << endl << exception.what() << endl;
      throw;
    }
  }

  bool IsAudioIndexCorrect(size_t index) override {
    return index < audio_pool_.size();
  }

  weak_ptr<Audio> GetAudioByIndex(size_t index) override {
    if (!IsAudioIndexCorrect(index))
      throw out_of_range("Index is out of audio pool range");

    return audio_pool_[index];
  }

  ~Impl() override = default;
 private:
  vector<shared_ptr<Audio>> audio_pool_;

  vector<unique_ptr<ICommand>> commands_;

  weak_ptr<Audio> audio_to_modify_;

  string output_file_name;

  void ReadCommands(ifstream& config_stream) {
    map<string, unique_ptr<ICommandFactory>> factoryByCommandName;
    factoryByCommandName["mute"] = make_unique<MuteCommandFactory>(this);
    factoryByCommandName["mix"] = make_unique<MixCommandFactory>(this);
    factoryByCommandName["insert"] = make_unique<InsertCommandFactory>(this);

    for (string line; getline(config_stream, line);) {
      auto tokens = Split(line);

      if (factoryByCommandName.contains(tokens[0]))
        commands_.push_back(factoryByCommandName[tokens[0]]->CreateCommand(tokens));
      else
        throw invalid_argument("Unknown command name");
    }
  }

  static vector<string> Split(string const& line) {
    stringstream line_stream(line);
    vector<string> tokens;
    for (string token; line_stream >> token;)
      tokens.push_back(token);
    return tokens;
  }
};

Application::Application(AppParameters& parameters) :
    pimpl_{make_unique<Impl>(parameters)} {
}

void Application::Run() {
  pimpl_->Run();
}

bool Application::IsAudioIndexCorrect(size_t index) {
  return pimpl_->IsAudioIndexCorrect(index);
}

weak_ptr<Audio> Application::GetAudioByIndex(size_t index) {
  return pimpl_->GetAudioByIndex(index);
}

Application::~Application() = default;
}