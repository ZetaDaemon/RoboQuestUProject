#include "Modifier_Stat.h"

UModifier_Stat::UModifier_Stat() {
    this->TargetStat = EStat::Health;
    this->Type = EModifierStatType::Flat;
    this->Value = 0.00f;
    this->bModifiedBaseValue = false;
}

void UModifier_Stat::UpdateValue(float NewValue) {
}


