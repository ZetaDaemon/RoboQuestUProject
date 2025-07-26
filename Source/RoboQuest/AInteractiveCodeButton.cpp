#include "AInteractiveCodeButton.h"

AAInteractiveCodeButton::AAInteractiveCodeButton(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->InputDigit = 0;
    this->DoorReward = EPermanentReward::KeyBot;
    this->InitMaterial = NULL;
    this->PressedMaterial = NULL;
    this->DisabledMaterial = NULL;
}

void AAInteractiveCodeButton::Reset() {
}

void AAInteractiveCodeButton::OnPressed() {
}


void AAInteractiveCodeButton::Disable() {
}

void AAInteractiveCodeButton::AllDoorsRegistered(AATile* Tile) {
}


