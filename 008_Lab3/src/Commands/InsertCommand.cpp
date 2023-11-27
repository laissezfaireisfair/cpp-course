#include "Commands/InsertCommand.h"

namespace audioConverter {
class InsertCommand::Impl {
 public:
  Impl(int insert_after_sec, std::weak_ptr<Audio>& audio_to_insert) :
      insert_after_sec_{insert_after_sec},
      audio_to_insert_{audio_to_insert} {
  }

  void Run(std::weak_ptr<Audio>& audio_to_modify) {
    auto& to_modify = *audio_to_modify.lock();
    auto& to_insert = *audio_to_insert_.lock();

    size_t insert_after_sample = insert_after_sec_ * to_modify.kSamples_per_second_;

    size_t end_of_new_block = insert_after_sample + to_insert.SamplesCount();

    if (end_of_new_block > to_modify.SamplesCount())
      to_modify.Extend(end_of_new_block + 1);

    for (size_t i = 0; i < to_insert.SamplesCount(); ++i)
      to_modify[insert_after_sample + i] = to_insert[i];
  }

  ~Impl() = default;

 private:
  int insert_after_sec_;

  std::weak_ptr<Audio> audio_to_insert_;
};

InsertCommand::InsertCommand(int insert_after_sec, std::weak_ptr<Audio>& audio_to_insert) :
    pimpl_{std::make_unique<Impl>(insert_after_sec, audio_to_insert)} {
}

void InsertCommand::Run(std::weak_ptr<Audio>& audio_to_modify) {
  pimpl_->Run(audio_to_modify);
}

InsertCommand::~InsertCommand() = default;
}