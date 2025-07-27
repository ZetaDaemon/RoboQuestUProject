#include "CharacterDataAsset.h"

UCharacterDataAsset::UCharacterDataAsset() {
    this->ActorDynamicLoadingRange[0] = 0.00f;
    this->ActorDynamicLoadingRange[1] = 0.00f;
    this->TemporaryNearStateDuration = 5.00f;
    this->RagdollDuration[0] = 0.00f;
    this->RagdollDuration[1] = 0.00f;
    this->RagdollDuration[2] = 0.00f;
    this->RagdollDuration[3] = 0.00f;
    this->RagdollDuration[4] = 0.00f;
    this->CurveImpactForceVelocity = NULL;
    this->CurveImpactForceImpulse = NULL;
    this->ZDeathImpulseModifier = 100000.00f;
}


