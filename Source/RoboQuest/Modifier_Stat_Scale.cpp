#include "Modifier_Stat_Scale.h"

UModifier_Stat_Scale::UModifier_Stat_Scale() {
    this->ScaleValue = 0.00f;
    this->bScaleWithCurve = false;
    this->ScaleCurve = NULL;
}

void UModifier_Stat_Scale::UpdateScaleValue(float NewValue) {
}

void UModifier_Stat_Scale::UpdateScaleAmount(int32 NewScaleAmount) {
}


