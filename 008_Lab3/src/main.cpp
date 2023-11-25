#include <iostream>
#include "Application.h"
#include "WavEncoder.h"

int main(int argc, char* argv[]) {
  int const min_arguments_count = 3;
  if (argc < min_arguments_count) {
    std::cerr << "Not enough arguments" << std::endl;
    return 1;
  }

  std::vector<std::string> arguments(argc - 1);
  for (int i = 1; i < argc; ++i)  // Skip exec path
    arguments[i - 1] = argv[i];

  audioConverter::AppParameters parameters{
      .output_file_name = arguments[1],
      .config_file_name = arguments[0],
      .input_file_names = std::vector<std::string>(arguments.begin() + 2, arguments.end())
  };

  audioConverter::Application application(parameters);

  application.Run();

  return 0;
}
