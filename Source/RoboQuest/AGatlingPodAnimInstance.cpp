#include "AGatlingPodAnimInstance.h"

UAGatlingPodAnimInstance::UAGatlingPodAnimInstance() {
    this->bIsAttacking = false;
    this->PreshootRatio = 0.00f;
    this->AnimBarrelRotationZ = 0.00f;
}

void UAGatlingPodAnimInstance::OnUpdatePreshootRatio(float NewPreshootRatio) {
}

void UAGatlingPodAnimInstance::OnNotifySkillUsed(UASkill* Skill, bool bIsUsed) {
}

void UAGatlingPodAnimInstance::OnEndInitialization() {
}


