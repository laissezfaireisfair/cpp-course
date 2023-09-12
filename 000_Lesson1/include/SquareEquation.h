#pragma once

#include <vector>
#include <string>

namespace Equations
{
    class SquareEquation
    {
    public:
        SquareEquation(double a, double b, double c);

        std::vector<double> GetSolution() const;

        std::string ToString() const;

    private:
        double a;
        double b;
        double c;
    };
}