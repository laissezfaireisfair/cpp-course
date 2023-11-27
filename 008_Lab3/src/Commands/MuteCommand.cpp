#include "Commands/MuteCommand.h"

namespace audioConverter {
using std::make_unique;
using std::to_string;

class MuteCommand::Impl {
 public:
  Impl(int mute_from_sec, int mute_to_sec) :
      mute_from_sec_{mute_from_sec},
      mute_to_sec_{mute_to_sec} {
  }

  void Run(weak_ptr<Audio>& audio_to_modify) const {
    auto& to_modify = *audio_to_modify.lock();

    size_t mute_from_sample = mute_from_sec_ * to_modify.kSamples_per_second_;
    size_t mute_to_sample = mute_to_sec_ * to_modify.kSamples_per_second_;
    for (size_t i = mute_from_sample; i < to_modify.SamplesCount() && i < mute_to_sample; ++i)
      to_modify[mute_from_sample + i] = 0;
  }

  string Description() const {
    return "Mute from " + to_string(mute_from_sec_) + " to " + to_string(mute_to_sec_) + " seconds";
  }

  ~Impl() = default;

 private:
  int mute_from_sec_;

  int mute_to_sec_;
};


MuteCommand::MuteCommand(int mute_from_sec, int mute_to_sec) :
    pimpl_{make_unique<Impl>(mute_from_sec, mute_to_sec)} {
}

void MuteCommand::Run(weak_ptr<Audio>& audio_to_modify) {
  pimpl_->Run(audio_to_modify);
}

string MuteCommand::Description() {
  return pimpl_->Description();
}

MuteCommand::~MuteCommand() = default;
}