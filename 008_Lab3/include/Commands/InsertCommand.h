#pragma once

#include "ICommand.h"

namespace audioConverter {
class InsertCommand : public ICommand {
 public:
  InsertCommand(int insert_after_sec, wptr<Audio>& audio_to_insert);

  void Run(wptr<Audio>& audio_to_modify) override;

  ~InsertCommand() override;

 private:
  int insert_after_sec_;

  wptr<Audio> audio_to_insert_;
};
}