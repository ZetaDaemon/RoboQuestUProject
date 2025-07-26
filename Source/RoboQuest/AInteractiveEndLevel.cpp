#include "AInteractiveEndLevel.h"

AAInteractiveEndLevel::AAInteractiveEndLevel(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void AAInteractiveEndLevel::OnUpdateLocalization(const FString& NewLanguage) {
}


float AAInteractiveEndLevel::GetFadeToBlackDelayBeforeEndLevel_Implementation() const {
    return 0.0f;
}


void AAInteractiveEndLevel::EndLevel() {
}

void AAInteractiveEndLevel::DelayedFadeToBlack() {
}


