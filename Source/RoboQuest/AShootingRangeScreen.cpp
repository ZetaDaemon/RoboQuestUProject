#include "AShootingRangeScreen.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshComponent -FallbackName=StaticMeshComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=UMG -ObjectName=WidgetComponent -FallbackName=WidgetComponent

AAShootingRangeScreen::AAShootingRangeScreen(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ScreenMesh"));
    this->ScreenMesh = (UStaticMeshComponent*)RootComponent;
    this->ScreenCollisionMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ScreenCollisionMesh"));
    this->ScreenWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("ScreenWidget"));
    this->LockedMesh = NULL;
    this->UnlockedMesh = NULL;
    this->CollisionMesh = NULL;
    this->Index = 0;
    this->GameStateRef = NULL;
    this->GameInstanceRef = NULL;
    this->ScreenWidget->SetupAttachment(RootComponent);
}

void AAShootingRangeScreen::OnPressedLinkedButton_Implementation() {
}

void AAShootingRangeScreen::InitializeMesh(bool bUnlocked) {
}

AAGameState* AAShootingRangeScreen::GetGameStateRef() {
    return NULL;
}

UAGameInstance* AAShootingRangeScreen::GetGameInstanceRef() {
    return NULL;
}


