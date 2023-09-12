#include <iostream>
#include <regex>

bool check_braces_and_remove(std::string const &string) {
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

std::string try_parse_number(std::regex regex, std::string &&raw) {
  auto areBracesOk = check_braces_and_remove(raw);
  if (!areBracesOk)
    return std::string();
  auto filtered = std::ranges::fi

  std::smatch match;
  auto isFound = std::regex_match(raw, match, regex);
  if (!isFound)
    return std::string();

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

  return std::string();
}

int main() {
  std::string input;
  std::getline(std::cin, input);

  static const std::regex regex(
      "((\\+ *7)|8)-? *-?\\d-? *-?\\d-? *-?\\d-? *-?\\d-? *-?\\d-? *-?\\d-? *-?\\d-? *-?\\d-? *-?\\d-? *-?\\d");
  auto parsed = try_parse_number(regex, std::move(input));

  if (parsed.empty())
    std::cout << "error" << std::endl;
  else
    std::cout << parsed << std::endl;

  return 0;
}
