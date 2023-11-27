#include <iostream>
#include "Application.h"

using std::cerr;
using std::endl;
using std::vector;
using std::string;

int main(int argc, char* argv[]) {
  int const min_arguments_count = 3;
  if (argc < min_arguments_count) {
    cerr << "Not enough arguments" << endl;
    return 1;
  }

  vector<string> arguments(argc - 1);
  for (int i = 1; i < argc; ++i)  // Skip exec path
    arguments[i - 1] = argv[i];

  audioConverter::AppParameters parameters{
      .output_file_name = arguments[1],
      .config_file_name = arguments[0],
      .input_file_names =   vector<string>(arguments.begin() + 2, arguments.end())
  };

  audioConverter::Application application(parameters);

  application.Run();

  return 0;
}
