#pragma once

#include <fstream>

#include "Audio.h"

namespace audioConverter {
class WavEncoder {
 public:
  static Audio ReadAudio(std::istream& steam);

  static void WriteAudio(std::istream& steam, Audio const& audio);
};
}