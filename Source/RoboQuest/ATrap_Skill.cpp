#include "ATrap_Skill.h"
#include "ASkillManager.h"

AATrap_Skill::AATrap_Skill(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SkillManager = CreateDefaultSubobject<UASkillManager>(TEXT("SkillManager"));
}


