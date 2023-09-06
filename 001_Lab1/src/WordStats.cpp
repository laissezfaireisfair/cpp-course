#include <string>

#include "WordStats.h"

TextAnalyser::WordStats::WordStats(std::string &word, int appearances) : word(word), appearances(appearances) {
}

const std::string &TextAnalyser::WordStats::GetWord() const {
    return word;
}

int TextAnalyser::WordStats::GetAppearances() const {
    return appearances;
}

int TextAnalyser::WordStats::GetPercentage(int totalWords) const {
    return appearances * 100 / totalWords;
}
