#include "StatusSound.h"

FStatusSound::FStatusSound() {
    this->StartSound = NULL;
    this->LoopSound = NULL;
    this->EndSound = NULL;
    this->TriggerFX = NULL;
    this->TriggerSocketLocation = ESocketLocation::Head;
    this->LoopFX = NULL;
    this->LoopSocketLocation = ESocketLocation::Head;
    this->EndFX = NULL;
    this->EndSocketLocation = ESocketLocation::Head;
}

