#include "ACodeScreen.h"

AACodeScreen::AACodeScreen(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SecretDoor = EPermanentReward::LastIndex;
    this->DigitsCount = 3;
    this->GameStateRef = NULL;
    this->LevelGeneratorRef = NULL;
}

void AACodeScreen::SetSuccessState() {
}

void AACodeScreen::SetErrorState() {
}

void AACodeScreen::SetDigit(uint8 Digit, int32 Order) {
}







ACharacter_Player* AACodeScreen::GetLocalPlayerRef() const {
    return NULL;
}

AAPlayerController* AACodeScreen::GetLocalPlayerControllerRef() const {
    return NULL;
}

int32 AACodeScreen::GetCode() {
    return 0;
}

void AACodeScreen::Disable(int32 Code) {
}

void AACodeScreen::Clear() {
}


