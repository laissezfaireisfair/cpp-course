#pragma once

#include <vector>
#include <cstdint>

namespace audioConverter {
class Audio {
 public:
  explicit Audio(size_t samples_count);

  int16_t& operator[](size_t position);

  int16_t const& operator[](size_t position) const;

  size_t SamplesCount() const;

 private:
  std::vector<int16_t> samples_;

  int const kSamples_per_second_ = 44100;
};
}