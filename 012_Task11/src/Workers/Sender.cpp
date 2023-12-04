#include "Workers/Sender.h"

namespace task11 {
using std::endl;

Sender::Sender(ostream& stream) :
    stream_{stream} {
}

Sender::~Sender() = default;

void Sender::Process(unique_ptr<Email> email) {
  stream_ << email->From() << endl;
  stream_ << email->To() << endl;
  stream_ << email->Body() << endl;
}
}