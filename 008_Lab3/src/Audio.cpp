#include "Audio.h"

#include <utility>

namespace audioConverter {
using std::make_unique;

class Audio::Impl {
 public:
  explicit Impl(string name, size_t samples_count) :
      name_{std::move(name)},
      samples_(samples_count, 0) {
  }

  int16_t& operator[](size_t position) {
    return samples_[position];
  }

  int16_t const& operator[](size_t position) const {
    return samples_[position];
  }

  size_t SamplesCount() const {
    return samples_.size();
  }

  void Extend(size_t new_size) {
    samples_.resize(new_size, 0);
  }

  string Name() const {
    return name_;
  }

  ~Impl() = default;

 private:
  string name_;

  vector<int16_t> samples_;
};


Audio::Audio(const string& name, size_t samples_count) :
    pimpl_{make_unique<Impl>(name, samples_count)} {
}

int16_t& Audio::operator[](size_t position) {
  return pimpl_->operator[](position);
}

int16_t const& Audio::operator[](size_t position) const {
  return pimpl_->operator[](position);
}

size_t Audio::SamplesCount() const {
  return pimpl_->SamplesCount();
}

void Audio::Extend(size_t new_size) {
  pimpl_->Extend(new_size);
}

string Audio::Name() const {
  return pimpl_->Name();
}

Audio::~Audio() = default;
}