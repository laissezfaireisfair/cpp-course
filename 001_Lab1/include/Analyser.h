#pragma once

#include <map>

#include "WordStats.h"

namespace TextAnalyser {
    class Analyser {
    public:
        Analyser();

        void AddLine(std::string &line);

        [[nodiscard]] std::vector<TextAnalyser::WordStats> GetStats() const;

        [[nodiscard]] int GetTotalWords() const;

    private:
        int totalWords;
        std::map<std::string, int> appearancesByWord;
    };
}