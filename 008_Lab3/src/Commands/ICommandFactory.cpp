#include <regex>
#include <charconv>

#include "Commands/ICommandFactory.h"

namespace audioConverter {
using std::regex;
using std::invalid_argument;
using std::smatch;
using std::from_chars;
using std::out_of_range;

ICommandFactory::ICommandFactory(IAudioPoolFacade* audio_pool_facade) :
    audio_pool_facade_{audio_pool_facade} {
}

weak_ptr<Audio> ICommandFactory::GetAudioFromPoolByAlias(string const& alias) {
  static regex alias_regex(R"([$]\d)");
  if (!regex_match(alias, alias_regex))
    throw invalid_argument("Bad audio stream alias");

  static regex number_regex(R"(\d)");
  smatch match_results;
  regex_search(alias, match_results, number_regex);
  string number_str = match_results[0].str();

  int64_t number = 0;
  from_chars(number_str.data(), number_str.data() + number_str.size(), number);

  --number;  // User count from 1

  if (number < 0 || !audio_pool_facade_->IsAudioIndexCorrect(size_t(number)))
    throw out_of_range("Alias is out of audio stream pool range");

  return audio_pool_facade_->GetAudioByIndex(number);
}

ICommandFactory::~ICommandFactory() = default;
}