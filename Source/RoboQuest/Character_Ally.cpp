#include "Character_Ally.h"

ACharacter_Ally::ACharacter_Ally(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DifficultyHealthModifier = NULL;
    this->ModHealth = NULL;
    this->DeathFX = NULL;
    this->DeathSound = NULL;
}

void ACharacter_Ally::SetActivationDuringLevelGeneration(bool bIsGenerating) {
}

void ACharacter_Ally::RemoveElemental_Implementation(EElement Element) {
}

void ACharacter_Ally::OnAllyKill(FRQDamageInfo DamageInfo) {
}

void ACharacter_Ally::InitElemental_Implementation(EElement Element, float ElementalRatio, bool bInit) {
}


