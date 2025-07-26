#include "AJumpad.h"

AAJumpad::AAJumpad(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Location = EJumpadLocation::Both;
    this->TriggerSound = NULL;
    this->TriggerSoundHaptic = NULL;
    this->ArrowComponent = NULL;
    this->TriggerAudioComponent = NULL;
    this->SpecialTile = NULL;
    this->LevelGeneratorRef = NULL;
    this->GameStateRef = NULL;
}

void AAJumpad::SetJumpadActivate(bool bActivate) {
}

void AAJumpad::OnEndJumpadLockInput(ACharacter_Player* Player) {
}



void AAJumpad::OnBeginTriggerBoxOverlap(UPrimitiveComponent* OverlappedComp, AActor* OverlappedActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}



AALevelGenerator* AAJumpad::GetLevelGeneratorRef() const {
    return NULL;
}


AAGameState* AAJumpad::GetGameStateRef() const {
    return NULL;
}


