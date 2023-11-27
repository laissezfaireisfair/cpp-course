#include "Audio.h"

namespace audioConverter {
Audio::Audio(size_t samples_count) :
    samples_(samples_count, 0) {
}

int16_t& Audio::operator[](size_t position) {
  return samples_[position];
}

int16_t const& Audio::operator[](size_t position) const {
  return samples_[position];
}
size_t Audio::SamplesCount() const {
  return samples_.size();
}

void Audio::Extend(size_t new_size) {
  samples_.resize(new_size, 0);
}
}