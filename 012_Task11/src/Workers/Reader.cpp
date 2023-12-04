#include <fstream>

#include "Workers/Reader.h"

namespace task11 {
using std::make_unique;

Reader::Reader(istream& stream) :
    stream_{stream} {
}

Reader::~Reader() = default;

void Reader::Process(unique_ptr<Email> email) {
  PassOn(std::move(email));
}

void Reader::Run() {
  while (true) {
    string from;
    if (!getline(stream_, from))
      break;
    string to;
    if (!getline(stream_, to))
      break;
    string body;
    if (!getline(stream_, body))
      break;
    auto email = make_unique<Email>(std::move(from), std::move(to), std::move(body));

    Process(std::move(email));
  }
}
}