#include <regex>
#include <charconv>

#include "Commands/ICommandFactory.h"

namespace audioConverter {
ICommandFactory::ICommandFactory(IAudioPoolFacade* audio_pool_facade) :
    audio_pool_facade_{audio_pool_facade} {
}

std::weak_ptr<Audio> ICommandFactory::GetAudioFromPoolByAlias(std::string const& alias) {
  static std::regex alias_regex(R"([$]\d)");
  if (!std::regex_match(alias, alias_regex))
    throw std::invalid_argument("Bad audio stream alias");

  static std::regex number_regex(R"(\d)");
  std::smatch match_results;
  std::regex_search(alias, match_results, number_regex);
  std::string number_str = match_results[0].str();

  int64_t number = 0;
  std::from_chars(number_str.data(), number_str.data() + number_str.size(), number);

  --number;  // User count from 1

  if (number < 0 || !audio_pool_facade_->IsAudioIndexCorrect(size_t(number)))
    throw std::out_of_range("Alias is out of audio stream pool range");

  return audio_pool_facade_->GetAudioByIndex(number);
}

ICommandFactory::~ICommandFactory() = default;
}