#include "ATrap.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent

AATrap::AATrap(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    this->SceneRoot = (USceneComponent*)RootComponent;
    this->Type = ETrapType::Laser;
    this->bScalableDamage = false;
    this->Root_Activate = CreateDefaultSubobject<USceneComponent>(TEXT("Root_Activate"));
    this->Root_Deactivate = CreateDefaultSubobject<USceneComponent>(TEXT("Root_Deactivate"));
    this->DealDamageSound = NULL;
    this->GameplayTags = 0;
    this->bIsActivated = false;
    this->LevelGeneratorRef = NULL;
    this->GameStateRef = NULL;
    this->Root_Activate->SetupAttachment(RootComponent);
    this->Root_Deactivate->SetupAttachment(RootComponent);
}

void AATrap::SetTrapActivate(bool bActivate) {
}



void AATrap::DealDamage(AActor* DamagedActor, float Amount) {
}

void AATrap::DeactivatePermanently() {
}


