#pragma once

#include <vector>
#include <cstdint>

namespace audioConverter {
class Audio {
 public:
  explicit Audio(size_t samples_count);

  int16_t& operator[](size_t position);

 private:
  std::vector<int16_t> samples_;

  int const kSamples_per_second_ = 44100;
};
}