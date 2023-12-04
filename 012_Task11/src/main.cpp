#include <sstream>
#include <iostream>

#include "PipelineBuilder.h"

using std::string;
using std::istringstream;
using std::ostringstream;
using std::logic_error;
using std::exception;
using std::cerr;
using std::endl;
using task11::Email;
using task11::PipelineBuilder;

void TestSanity() {
  string input = (
      "erich@example.com\n"
      "richard@example.com\n"
      "Hello there\n"

      "erich@example.com\n"
      "ralph@example.com\n"
      "Are you sure you pressed the right button?\n"

      "ralph@example.com\n"
      "erich@example.com\n"
      "I do not make mistakes of that kind\n"
  );
  istringstream inStream(input);
  ostringstream outStream;

  PipelineBuilder builder(inStream);
  builder.FilterBy([](const Email& email) {
    return email.From() == "erich@example.com";
  });
  builder.CopyTo("richard@example.com");
  builder.Send(outStream);
  auto pipeline = builder.Build();

  pipeline->Run();

  string expectedOutput = (
      "erich@example.com\n"
      "richard@example.com\n"
      "Hello there\n"

      "erich@example.com\n"
      "richard@example.com\n"
      "Are you sure you pressed the right button?\n"

      "erich@example.com\n"
      "ralph@example.com\n"
      "Are you sure you pressed the right button?\n"
  );

  auto realOutput = outStream.str();
  if (expectedOutput != realOutput)
    throw logic_error("Unexpected output: " + realOutput);
}

int main() {
  try {
    TestSanity();
  }
  catch (exception& exception) {
    cerr << "Exception: " << exception.what() << endl;
    return 1;
  }
  catch (...) {
    cerr << "Unknown exception" << endl;
    return 2;
  }
  return 0;
}
