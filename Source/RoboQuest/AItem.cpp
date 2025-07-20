#include "AItem.h"

UAItem::UAItem() {
    this->BaseItemRef = NULL;
    this->RandomSeed = 0;
    this->PlayerRef = NULL;
    this->ItemType = EItemType::Perk;
    this->SparkFirerate = 0.00f;
    this->ClassSkillRef = NULL;
    this->BashSkillRef = NULL;
    this->WeaponSlotModifier = NULL;
}


void UAItem::OnRemoveWeaponSlot() {
}

void UAItem::OnApply_Implementation(bool bFromRunSave) {
}


bool UAItem::IsLocallyControlled() const {
    return false;
}

bool UAItem::IsElementalDamage(int32 GameplayTags) const {
    return false;
}

float UAItem::GetSparkFirerate() const {
    return 0.0f;
}

int32 UAItem::GetSparkAmount(UASkill* InSkill) const {
    return 0;
}

bool UAItem::GetSeededRandomResult(int32 Luck, int32 LuckIncrementByFail, float FireRate) {
    return false;
}

UParticleSystem* UAItem::GetElementalTrail(int32 GameplayTags) const {
    return NULL;
}

float UAItem::GetCustomFloatValue(FName PropertyName) const {
    return 0.0f;
}

UAPlayerSkill* UAItem::GetClassSkill() const {
    return NULL;
}

UAPlayerSkill* UAItem::GetBashSkill() const {
    return NULL;
}

bool UAItem::GetBaseSeededRandomResult() {
    return false;
}


