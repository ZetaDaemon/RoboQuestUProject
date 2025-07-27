#include "ABossTriggerBox.h"
#include "Components/BoxComponent.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshComponent -FallbackName=StaticMeshComponent
#include "Components/StaticMeshComponent.h"

AABossTriggerBox::AABossTriggerBox(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}

void AABossTriggerBox::OnPlayerDisconnected(ACharacter_Player* DisconnectedPlayer) {
}

void AABossTriggerBox::OnBeginTriggerBoxOverlap(UPrimitiveComponent* OverlappedComp, AActor* OverlappedActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}


