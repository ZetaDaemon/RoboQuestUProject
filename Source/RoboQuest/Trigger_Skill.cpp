#include "Trigger_Skill.h"

UTrigger_Skill::UTrigger_Skill() {
    this->PlayerCharacter = NULL;
    this->GameplayTags = 0;
    this->bOnlyWeaponSkill = false;
    this->TriggerWeapon = NULL;
}

void UTrigger_Skill::OnWeaponChange(AAWeapon* NewWeapon) {
}

void UTrigger_Skill::OnUpdateSkillTag(UASkill* NewSkill) {
}

void UTrigger_Skill::OnSpawnSomeone(ACharacter_AI* SpawnedCharacter, bool bIsStart) {
}

void UTrigger_Skill::OnAddSkill(UASkill* NewSkill) {
}


