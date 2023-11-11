#include "Commands/MuteCommand.h"

namespace audioConverter {

MuteCommand::MuteCommand(int mute_from_sec, int mute_to_sec) :
    mute_from_sec_(mute_from_sec),
    mute_to_sec_(mute_to_sec) {
}

void MuteCommand::Run(wptr<Audio>& audio_to_modify) {
  // TODO: Implement
}

MuteCommand::~MuteCommand() = default;
}