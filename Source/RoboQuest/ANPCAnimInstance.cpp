#include "ANPCAnimInstance.h"

UANPCAnimInstance::UANPCAnimInstance() {
    this->OwningComponent = NULL;
    this->OwningActor = NULL;
    this->PitchAIM = 0.00f;
    this->YawAIM = 0.00f;
    this->AIMSpeed = 100.00f;
    this->AIMAlpha = 0.00f;
    this->MaxAIMDistance = 1400.00f;
    this->AIMAlphaSpeed = 6.00f;
    this->bPlayerInAIM = false;
    this->OwningPlayerRef = NULL;
}


