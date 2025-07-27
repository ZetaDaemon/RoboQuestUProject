#include "AFreezeTrap.h"
#include "ETrapType.h"

AAFreezeTrap::AAFreezeTrap(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Type = ETrapType::Freeze;
    this->bScalableDamage = true;
    this->IdleAudioComponent = NULL;
    this->TriggerAudioComponent = NULL;
    this->SmokeIdleFXComponent = NULL;
    this->SmokeTriggerFXComponent = NULL;
    this->IdleSound = NULL;
    this->TriggerSound = NULL;
    this->SmokeIdleFX = NULL;
    this->SmokeTriggerFX = NULL;
    this->BlowingDuration = 2.00f;
    this->IdleDuration = 2.00f;
    this->Damage = 6.00f;
    this->AppliedStatus = EStatus::Slowed;
    this->StatusDuration = 2.00f;
}


