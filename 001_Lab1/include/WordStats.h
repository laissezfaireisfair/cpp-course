#pragma once

namespace TextAnalyser {
    class WordStats {
    public:
        explicit WordStats(std::string &word, int appearances);

        const std::string &GetWord() const;

        int GetAppearances() const;

        int GetPercentage(int totalWords) const;

    private:
        std::string word;
        int appearances;
    };
}