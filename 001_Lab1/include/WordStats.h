#pragma once

namespace TextAnalyser {
    class WordStats {
    public:
        explicit WordStats(std::string &word, int appearances);

        [[nodiscard]] const std::string &GetWord() const;

        [[nodiscard]] int GetAppearances() const;

        [[nodiscard]] int GetPercentage(int totalWords) const;

    private:
        std::string word;
        int appearances;
    };
}