#pragma once

#include <vector>
#include <cstdint>

namespace audioConverter {
using std::vector;

class Audio {
 public:
  explicit Audio(size_t samples_count);

  int16_t& operator[](size_t position);

  int16_t const& operator[](size_t position) const;

  size_t SamplesCount() const;

  void Extend(size_t new_size);

  int const kSamples_per_second_ = 44100;

 private:
  vector<int16_t> samples_;
};
}