#include <iostream>
#include <string>
#include <sstream>
#include <numeric>
using namespace std;

class Rational {
 public:
  Rational() {
    numerator = 0;
    denominator = 1;
  }

  Rational(int numerator, int denominator) {
    if (denominator == 0) {
      stringstream ss;
      ss << "Denominator must not be zero, got: numerator=" << numerator << ", denominator =" << denominator;
      throw invalid_argument(ss.str());
    }

    this->numerator = numerator;
    this->denominator = denominator;

    simplify();
  }

  int Numerator() const {
    return numerator;
  }

  void SetNumerator(int num) {
    numerator = num;
  }

  int Denominator() const {
    return denominator;
  }

  void SetDenominator(int denom) {
    denominator = denom;
  }

  Rational operator+(const Rational &other) const {
    int newDenominator = denominator * other.denominator / gcd(denominator, other.denominator);
    int leftNumerator = numerator * (newDenominator / denominator);
    int rightNumerator = other.numerator * (newDenominator / other.denominator);
    int newNumerator = leftNumerator + rightNumerator;
    auto result = Rational(newNumerator, newDenominator);
    result.simplify();
    return result;
  }

  Rational operator*(const Rational &other) const {
    auto rational = Rational(numerator * other.numerator, denominator * other.denominator);
    rational.simplify();
    return rational;
  }

  Rational operator/(const Rational &other) const {
    auto upsideDown = Rational(other.denominator, other.numerator);
    return operator*(upsideDown);
  }

  Rational operator-(const Rational &other) const {
    Rational negated(-1 * other.numerator, other.denominator);
    return this->operator+(negated);
  }

  bool operator==(const Rational &other) const {
    return numerator * other.denominator == denominator * other.numerator;
  }

 private:
  int numerator;
  int denominator;

  void simplify() {
    int divider = gcd(numerator, denominator);
    numerator /= divider;
    denominator /= divider;
  }
};

ostream &operator<<(ostream &out, const Rational &rational) {
  out << rational.Numerator() << "/" << rational.Denominator();
  return out;
}

istream &operator>>(istream &in, Rational &rational) {
  int numerator, denominator;
  in >> numerator >> denominator;
  rational.SetNumerator(numerator);
  rational.SetDenominator(denominator);
  return in;
}

int main() {
  string input;
  getline(cin, input);
  stringstream ss(input);
  Rational r1, r2;
  char operation;
  try {
    ss >> r1;
    ss.ignore(1);
    ss >> operation;
    ss.ignore(1);
    ss >> r2;
  } catch (exception &ex) {
    cout << "Invalid argument" << endl;
    return 1;
  }
  Rational res;
  try {
    switch (operation) {
      case '+': {
        res = r1 + r2;
        break;
      }
      case '-': {
        res = r1 - r2;
        break;
      }
      case '*': {
        res = r1 * r2;
        break;
      }
      case '/': {
        res = r1 / r2;
        break;
      }
      default: {
        cout << "Invalid operation" << endl;
      }
    }
    cout << res;
  }
  catch (exception &ex) {
    cout << "Division by zero" << endl;
    return 2;
  }

  return 0;
}
