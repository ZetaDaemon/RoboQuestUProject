#include "AShootingRangeScreen.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshComponent -FallbackName=StaticMeshComponent
#include "Components/StaticMeshComponent.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=UMG -ObjectName=WidgetComponent -FallbackName=WidgetComponent

AAShootingRangeScreen::AAShootingRangeScreen(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
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


