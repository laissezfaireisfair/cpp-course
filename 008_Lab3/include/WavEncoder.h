#pragma once

#include <fstream>
#include <memory>

#include "Audio.h"

namespace audioConverter {
class WavEncoder {
 public:
  static std::shared_ptr<Audio> ReadAudio(std::istream& steam);

  static void WriteAudio(std::ostream& steam, Audio const& audio);
};
}