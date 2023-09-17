#include <iostream>
#include <regex>

bool check_braces(std::string const& string) {
  int leftBracesCount = 0;
  int rightBracesCount = 0;

  for (auto s : string) {
    if (s == '(') {
      if (leftBracesCount > 0)
        return false;
      ++leftBracesCount;
    }

    if (s == ')') {
      if (rightBracesCount > 0 || leftBracesCount <= rightBracesCount)
        return false;
      ++rightBracesCount;
    }
  }

  return leftBracesCount == rightBracesCount;
}

std::string try_parse_number(std::regex const & regex, std::regex const & badPattern, std::string && raw) {
  auto areBracesOk = check_braces(raw);
  if (!areBracesOk)
    return {};

  std::smatch match;
  auto isFound = std::regex_match(raw, match, regex);
  if (!isFound)
    return {};

  auto isContainBadPattern = std::regex_search(raw, badPattern);
  if (isContainBadPattern)
    return {};

  std::string formatted("+7");
  bool isFirstSkipped = false;
  for (auto s : raw) {
    if ('0' <= s && s <= '9') {
      if (isFirstSkipped)
        formatted.push_back(s);
      else
        isFirstSkipped = true;
    }
  }

  return formatted;
}

int main() {
  std::string input;
  std::getline(std::cin, input);

  static const std::regex regex(R"rgx(((\+ *7)|8)([- ()]*\d){10})rgx");
  static const std::regex badPattern(R"rgx(--)rgx");
  auto parsed = try_parse_number(regex, badPattern, std::move(input));

  if (parsed.empty())
    std::cout << "error" << std::endl;
  else
    std::cout << parsed << std::endl;

  return 0;
}
