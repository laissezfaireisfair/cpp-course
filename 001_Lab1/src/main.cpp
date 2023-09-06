#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Analyser.h"

int main(int argc, char **argv) {
    std::string const &outputFileName = std::string("output.csv");

    if (argc != 2) {
        std::cout << "Wrong number of arguments. Exiting..." << std::endl;
        return 1;
    }

    auto fileName = std::string(argv[1]);

    auto analyser = TextAnalyser::Analyser();

    auto fin = std::ifstream(fileName);
    for (std::string line; std::getline(fin, line);)
        analyser.AddLine(line);
    fin.close();

    auto stats = analyser.GetStats();
    auto totalWords = analyser.GetTotalWords();

    auto fout = std::ofstream(outputFileName);
    for (const auto &wordStat: stats)
        fout << wordStat.GetWord() << ", " << wordStat.GetAppearances() << ", " << wordStat.GetPercentage(totalWords) << std::endl;

    fout.close();

    return 0;
}
