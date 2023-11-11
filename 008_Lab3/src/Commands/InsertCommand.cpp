#include "Commands/InsertCommand.h"

namespace audioConverter {

InsertCommand::InsertCommand(int insert_after_sec, wptr<Audio>& audio_to_insert) :
    insert_after_sec_(insert_after_sec),
    audio_to_insert_(audio_to_insert) {
}

void InsertCommand::Run(wptr<Audio>& audio_to_modify) {
  // TODO: Implement
}

InsertCommand::~InsertCommand() = default;
}