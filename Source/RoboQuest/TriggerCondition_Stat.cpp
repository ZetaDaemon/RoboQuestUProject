#include "TriggerCondition_Stat.h"

UTriggerCondition_Stat::UTriggerCondition_Stat() {
    this->TriggerStat = EStat::Health;
    this->Comparator = EComparator::Equal;
    this->ValueType = EModifierStatType::Flat;
    this->targetType = ETargetType::Player;
    this->TriggerValue = 0.00f;
    this->BindWeapon = NULL;
}

void UTriggerCondition_Stat::OnWeaponChange(AAWeapon* NewWeapon) {
}

void UTriggerCondition_Stat::OnStatNotify(EStat Stat, float currentValue, float Value) {
}


