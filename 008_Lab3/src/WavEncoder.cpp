#include <iostream>
#include <cstring>

#include "WavEncoder.h"

namespace audioConverter {
#pragma pack(push, 1)
struct ChunkInfo {
  ChunkInfo() :
      chunk_id_{0, 0, 0, 0},
      chunk_size_{0} {
  }

  char chunk_id_[4];

  uint32_t chunk_size_;
};
#pragma pack(pop)

struct DataChunk {
  int16_t* data;

  uint64_t nb_of_samples;

  explicit DataChunk(uint64_t s) :
      data{new int16_t[s]},
      nb_of_samples{s} {
  }

  ~DataChunk() {
    delete[] data;
  }
};

Audio WavEncoder::ReadAudio(std::istream& stream) {
  constexpr char riff_id[4]{'R', 'I', 'F', 'F'};
  constexpr char data_id[4]{'d', 'a', 't', 'a'};
  ChunkInfo chunk_info;
  while (stream.read((char*) (&chunk_info), sizeof(chunk_info))) {
    bool is_riff_chunk = memcmp(chunk_info.chunk_id_, riff_id, 4) == 0;
    if (is_riff_chunk) {
      const int kRiffBytesToSkip = 4;
      stream.seekg(kRiffBytesToSkip, std::ios_base::cur);
      continue;
    }

    bool is_data_chunk = memcmp(chunk_info.chunk_id_, data_id, 4) == 0;
    if (is_data_chunk)
      break;
    stream.seekg(chunk_info.chunk_size_, std::ios_base::cur);
  }

  DataChunk data_chunk(chunk_info.chunk_size_ / sizeof(int16_t));
  stream.read((char*) data_chunk.data, chunk_info.chunk_size_);

  Audio audio(data_chunk.nb_of_samples);
  for (size_t i = 0; i < data_chunk.nb_of_samples; ++i)
    audio[i] = data_chunk.data[i];

  return audio;
}

void WavEncoder::WriteAudio(std::istream& stream, const Audio& audio) {
  // TODO: Implement
}
}