#pragma once

#include <map>

#include "WordStats.h"

namespace TextAnalyser {
    class Analyser {
    public:
        Analyser();

        void AddLine(std::string &line);

        std::vector<TextAnalyser::WordStats> GetStats() const;

        int GetTotalWords() const;

    private:
        int totalWords;
        std::map<std::string, int> appearancesByWord;
    };
}