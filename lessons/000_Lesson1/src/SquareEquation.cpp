#include <cmath>

#include "SquareEquation.h"

using namespace Equations;

SquareEquation::SquareEquation(double a, double b, double c) : a(a), b(b), c(c)
{
}

std::vector<double> SquareEquation::GetSolution() const {
    auto discriminant = b * b - 4 * a * c;

    if (discriminant < 0)
        return {};

    auto discriminantSqrt = sqrt(discriminant);

    if (discriminant == 0)
        return {-b / (2. * a)};

    return {(-b - discriminantSqrt) / (2 * a), (-b + discriminantSqrt) / (2 * a)};
}

std::string SquareEquation::ToString() const {
    return std::to_string(a) + " * x^2 + " + std::to_string(b) + " * x + " + std::to_string(c) + " = 0";
}
