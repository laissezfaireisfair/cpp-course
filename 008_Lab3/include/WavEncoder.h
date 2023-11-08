#pragma once

#include <fstream>
#include "Audio.h"

namespace audioConverter {
class WavEncoder {
 public:
  Audio ReadAudio(std::istream& steam);

  void WriteAudio(std::istream& steam, Audio const& audio);
};
}