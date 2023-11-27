#pragma once

#include "ICommand.h"

namespace audioConverter {
using std::unique_ptr;

class InsertCommand : public ICommand {
 public:
  InsertCommand(int insert_after_sec, weak_ptr<Audio>& audio_to_insert);

  void Run(weak_ptr<Audio>& audio_to_modify) override;

  string Description() override;

  ~InsertCommand() override;

 private:
  class Impl;
  unique_ptr<Impl> pimpl_;
};
}