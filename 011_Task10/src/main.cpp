#include <iostream>
#include <fstream>
#include "Reader.h"
#include "Writer.h"

using std::ifstream;
using std::string;
using std::cout;
using ini::Reader;
using ini::Reader;
using ini::Writer;

int main() {
  string const input_file_name = "input.ini";
  ifstream stream(input_file_name);

  auto reader = Reader();
  auto document = reader.ReadDocument(stream);

  stream.close();

  Writer::WriteDocument(document, cout);

  return 0;
}
