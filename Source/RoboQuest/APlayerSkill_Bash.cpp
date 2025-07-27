#include "APlayerSkill_Bash.h"

UAPlayerSkill_Bash::UAPlayerSkill_Bash(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RaycastTrailEmiterBeamIndex.AddDefaulted(1);
    this->BashModuleMesh = NULL;
    this->BashModuleAnimBlueprint = NULL;
    this->BashModuleUseAnimation = NULL;
    this->MeleeWeaponMesh = NULL;
    this->MeleeWeaponAnimBlueprint = NULL;
}


