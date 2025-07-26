#include "ALavaTrap.h"
#include "ETrapType.h"

AALavaTrap::AALavaTrap(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Type = ETrapType::Lava;
    this->IdleAudioComponent = NULL;
    this->IdleSound = NULL;
    this->BumpSound = NULL;
    this->Damage = 6.00f;
}

void AALavaTrap::UpdateSoundAttenuationBox() {
}



