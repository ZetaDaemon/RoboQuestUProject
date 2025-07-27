#include "AEnemyAnimInstance.h"

UAEnemyAnimInstance::UAEnemyAnimInstance() {
    this->CharacterAIRef = NULL;
    this->PitchAIM = 0.00f;
    this->YawAIM = 0.00f;
    this->bIsStunned = false;
    this->bIsIdle = false;
    this->HitBlend = 0.00f;
    this->AnimVelocityRatio = 0.00f;
}


