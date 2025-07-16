#include "Modifier_Damage.h"

UModifier_Damage::UModifier_Damage() {
    this->bSuperTextFeedback = false;
    this->bMegaTextFeedback = false;
    this->Type = EModifierStatType::Flat;
    this->Value = 0.00f;
}



