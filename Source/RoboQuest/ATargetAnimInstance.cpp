#include "ATargetAnimInstance.h"

UATargetAnimInstance::UATargetAnimInstance() {
    this->TargetRef = NULL;
    this->bIsDead = false;
    this->HitBlend = 0.00f;
    this->bIsStunned = false;
    this->bFirstState = false;
    this->bFlipMesh = false;
    this->Height = 0.00f;
}

void UATargetAnimInstance::OnTargetUpdateHitBlend(float NewHitBlend) {
}

void UATargetAnimInstance::OnTargetUpdateHeight(float NewHeight) {
}

void UATargetAnimInstance::OnTargetDispatchStatus(EStatus Status, bool bIsStart, float Duration) {
}

void UATargetAnimInstance::OnTargetDeath(AATarget* Target, bool bNewDead) {
}


