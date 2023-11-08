#pragma once

#include <string>
#include <vector>

namespace audioConverter{
struct AppParameters{
  std::string output_file_name;

  std::string config_file_name;

  std::vector<std::string> input_file_names;
};
}