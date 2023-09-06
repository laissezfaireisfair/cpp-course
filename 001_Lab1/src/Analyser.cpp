#include <string>
#include <vector>
#include <ranges>
#include <algorithm>

#include "Analyser.h"

TextAnalyser::Analyser::Analyser() : totalWords(0) {
    appearancesByWord = std::map<std::string, int>();
}

void TextAnalyser::Analyser::AddLine(std::string &line) {
    line.push_back(' ');

    auto word = std::string();
    for (auto symbol: line) {
        auto isLowLetter = 'a' <= symbol && symbol <= 'z';
        auto isBigLetter = 'A' <= symbol && symbol <= 'Z';
        auto isDigit = '0' <= symbol && symbol <= '9';
        if (isLowLetter || isBigLetter || isDigit)
        {
            word.push_back(symbol);
            continue;
        }

        if (word.empty())
            continue;

        if (appearancesByWord.contains(word))
            appearancesByWord[word] += 1;
        else
            appearancesByWord[word] = 1;

        ++totalWords;
        word.clear();
    }
}

std::vector<TextAnalyser::WordStats> TextAnalyser::Analyser::GetStats() const {
    auto stats = std::vector<TextAnalyser::WordStats>();
    for (auto const &wordAppearances: appearancesByWord) {
        auto word = wordAppearances.first;
        auto count = wordAppearances.second;
        stats.emplace_back(word, count);
    }
    std::ranges::sort(stats, [](TextAnalyser::WordStats const & a, TextAnalyser::WordStats const & b) {return a.GetAppearances() > b.GetAppearances(); });
    return stats;
}

int TextAnalyser::Analyser::GetTotalWords() const {
    return totalWords;
}
