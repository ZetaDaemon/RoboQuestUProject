#include "AArenaSpawner.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BillboardComponent -FallbackName=BillboardComponent
#include "Components/BoxComponent.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshComponent -FallbackName=StaticMeshComponent
#include "Components/StaticMeshComponent.h"

AAArenaSpawner::AAArenaSpawner(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void AAArenaSpawner::StartSpawning(ACharacter_Enemy* Enemy) {
}

void AAArenaSpawner::OnOverlappingCharacterDeath(const FRQDamageInfo& DamageInfo) {
}

void AAArenaSpawner::OnEndTriggerBoxOverlap(UPrimitiveComponent* OverlappedComp, AActor* OverlappedActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void AAArenaSpawner::OnBeginTriggerBoxOverlap(UPrimitiveComponent* OverlappedComp, AActor* OverlappedActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void AAArenaSpawner::OnAvailabilityTimerFinished() {
}

void AAArenaSpawner::OnAvailabilityChanged(bool bIsAvailable, EArenaSpawnerType SpawnerType) {
}

bool AAArenaSpawner::IsAvailable() const {
    return false;
}

AAGameState* AAArenaSpawner::GetGameStateRef() {
    return NULL;
}


