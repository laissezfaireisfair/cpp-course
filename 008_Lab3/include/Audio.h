#pragma once

#include <vector>
#include <cstdint>
#include <memory>

namespace audioConverter {
using std::vector;
using std::unique_ptr;
using std::string;

class Audio {
 public:
  explicit Audio(const string& name, size_t samples_count);

  int16_t& operator[](size_t position);

  int16_t const& operator[](size_t position) const;

  size_t SamplesCount() const;

  void Extend(size_t new_size);

  string Name() const;

  int const kSamples_per_second_ = 44100;

  ~Audio();

 private:
  class Impl;
  unique_ptr<Impl> pimpl_;
};
}