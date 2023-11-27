#pragma once

#include <fstream>
#include <memory>

#include "Audio.h"

namespace audioConverter {
using std::shared_ptr;
using std::istream;
using std::ostream;

class WavEncoder {
 public:
  static shared_ptr<Audio> ReadAudio(istream& steam);

  static void WriteAudio(ostream& steam, Audio const& audio);
};
}