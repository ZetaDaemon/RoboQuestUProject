#include "APlayerSkill_Scope.h"

UAPlayerSkill_Scope::UAPlayerSkill_Scope(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RaycastTrailEmiterBeamIndex.AddDefaulted(1);
    this->bIsScopped = false;
    this->ScopeChargedStartSound = NULL;
    this->ScopeChargedLoopSound = NULL;
    this->ScopeChargedMaxReachedSound = NULL;
    this->ChargedDamageModifier = NULL;
    this->ChargedScopeLoopingSoundComponent = NULL;
    this->bChargedScope = false;
    this->ScopeHUD = NULL;
}

void UAPlayerSkill_Scope::SetNewChargedDuration(float InDuration) {
}

void UAPlayerSkill_Scope::RemoveChargedScope() {
}

void UAPlayerSkill_Scope::OnWeaponUsedSkill(UASkill* Skill, bool bIsStarting) {
}

void UAPlayerSkill_Scope::InitializeChargedScope() {
}

float UAPlayerSkill_Scope::GetPostShootScopeDelay() {
    return 0.0f;
}

FAnimation UAPlayerSkill_Scope::GetOutAnimation_Implementation() {
    return FAnimation{};
}

FAnimation UAPlayerSkill_Scope::GetInAnimation_Implementation() {
    return FAnimation{};
}


