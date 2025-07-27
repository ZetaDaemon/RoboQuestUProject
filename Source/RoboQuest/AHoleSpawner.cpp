#include "AHoleSpawner.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=AudioComponent -FallbackName=AudioComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshComponent -FallbackName=StaticMeshComponent
#include "Components/StaticMeshComponent.h"
#include "Net/UnrealNetwork.h"

AAHoleSpawner::AAHoleSpawner(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void AAHoleSpawner::OnSpawnedEnemyDeath(const FRQDamageInfo& DamageInfo) {
}

void AAHoleSpawner::OnMulticastStartSpawnEnemy_Implementation() {
}

void AAHoleSpawner::OnEnemySpawned() {
}




AAGameState* AAHoleSpawner::GetGameStateRef() const {
    return NULL;
}

void AAHoleSpawner::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AAHoleSpawner, EnemyRef);
}


