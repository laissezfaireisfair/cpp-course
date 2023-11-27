#pragma once

#include <string>
#include <vector>

namespace audioConverter {
using std::string;
using std::vector;

struct AppParameters {
  string output_file_name;

  string config_file_name;

  vector<string> input_file_names;
};
}