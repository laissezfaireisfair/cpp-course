#include "Audio.h"

namespace audioConverter {
Audio::Audio(size_t samples_count) : samples_(samples_count, 0) {
}

int16_t& Audio::operator[](size_t position) {
  return samples_[position];
}
}