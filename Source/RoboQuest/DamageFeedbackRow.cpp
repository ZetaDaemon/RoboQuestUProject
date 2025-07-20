#include "DamageFeedbackRow.h"

FDamageFeedbackRow::FDamageFeedbackRow() {
    this->Position = ETextFeedbackPosition::Alternate;
    this->AlternateIndex = 0;
    this->bOffsetByDistance = false;
    this->FontSizeScale = 0.00f;
    this->bScaleByDistance = false;
    this->TextMaterial = NULL;
    this->ColorAnimation = ETextColorAnimation::None;
    this->TranslationAnimation = ETextTranslationAnimation::SemiAuto;
    this->ScaleAnimation = ETextScaleAnimation::SemiAuto;
    this->FadeAnimation = ETextFadeAnimation::Normal;
    this->Sound = NULL;
}

