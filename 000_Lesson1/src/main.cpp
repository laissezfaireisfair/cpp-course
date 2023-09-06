#include <iostream>
#include "SquareEquation.h"

int main() {
    int a, b, c;
    std::cout << "Type coefficients: ";
    std::cin >> a >> b >> c;

    auto equation = Equations::SquareEquation(a, b, c);

    auto description = equation.ToString();

    std::cout << std::endl << "Have equation: " << description << std::endl;

    auto solution = equation.GetSolution();

    std::cout << "Solutions: ";

    for (auto i: solution)
        std::cout << i << " ";

    return 0;
}
