#include "ASpecialSpawner.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ArrowComponent -FallbackName=ArrowComponent
#include "Components/BoxComponent.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent

AASpecialSpawner::AASpecialSpawner(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void AASpecialSpawner::OnEnemyDeath(const FRQDamageInfo& DamageInfo) {
}

void AASpecialSpawner::OnEndTriggerBoxOverlap(UPrimitiveComponent* OverlappedComp, AActor* OverlappedActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}


void AASpecialSpawner::OnBeginTriggerBoxOverlap(UPrimitiveComponent* OverlappedComp, AActor* OverlappedActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}


