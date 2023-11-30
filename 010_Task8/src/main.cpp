#include <iostream>
#include <fstream>
#include "Formation.h"

using std::cin;
using std::istream;
using std::ifstream;
using std::cout;
using std::endl;
using task8::Formation;

int main(int argc, char** argv) {
  istream* in;
  bool is_interactive_mode = argc < 2;
  if (is_interactive_mode)
    in = &cin;
  else
    in = new ifstream{argv[1]};

  if (is_interactive_mode)
    cout << "Sportsmen count: ";
  int sportsmen_count;
  *in >> sportsmen_count;

  auto formation = Formation();

  for (int i = 0; i < sportsmen_count; ++i) {
    if (is_interactive_mode)
      cout << "Sportsman number and number after: ";

    int number;
    int number_after;
    *in >> number >> number_after;

    formation.AddSportsman(number, number_after);
  }

  auto order = formation.GetOrder();

  cout << "Result order:";
  for (auto number : order)
    cout << " " << number;

  if (!is_interactive_mode)
    free(in);

  return 0;
}
