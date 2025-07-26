#include "ATile.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ArrowComponent -FallbackName=ArrowComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BoxComponent -FallbackName=BoxComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ChildActorComponent -FallbackName=ChildActorComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshComponent -FallbackName=StaticMeshComponent
#include "Templates/SubclassOf.h"

AATile::AATile(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void AATile::RandomizeMeshes() {
}

void AATile::OnStorySlotDestroyed(AActor* Actor) {
}

void AATile::OnReplicatedActorDestroyed(AActor* Actor) {
}

void AATile::OnLootSpawnedDestroyed(AActor* Actor) {
}

void AATile::OnDoorDestroyed(AActor* Actor) {
}


void AATile::OnBeginTileOverlap(UPrimitiveComponent* OverlappedComp, AActor* OverlappingActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void AATile::GetReplicatedActorsByClass(TSubclassOf<AActor> ActorClass, TArray<AActor*>& OutActors) const {
}

TArray<AActor*> AATile::GetLootSpawnedByType(FName LootType) const {
    return TArray<AActor*>();
}

AAPlayerController* AATile::GetLocalPlayerControllerRef() const {
    return NULL;
}

ACharacter_Player* AATile::GetLocalPlayerCharacterRef() const {
    return NULL;
}

AALightSelector* AATile::GetLightSelectorRef() const {
    return NULL;
}

AALevelGenerator* AATile::GetLevelGeneratorRef() const {
    return NULL;
}

AAGameState* AATile::GetGameStateRef() const {
    return NULL;
}

AAGameMode* AATile::GetGameModeRef() {
    return NULL;
}

TArray<AADoor*> AATile::GetExitingDoorsToSidePath() const {
    return TArray<AADoor*>();
}

TArray<AADoor*> AATile::GetExitingDoorsToMainPath() const {
    return TArray<AADoor*>();
}

TArray<AADoor*> AATile::GetExitingDoors() const {
    return TArray<AADoor*>();
}

TArray<AADoor*> AATile::GetEnteringDoors() const {
    return TArray<AADoor*>();
}

EDirection AATile::GetEnteringDirection() const {
    return EDirection::Up;
}

int32 AATile::GetEnemyLevel() const {
    return 0;
}


TArray<EDirection> AATile::GetConnectorOpenedDirections() const {
    return TArray<EDirection>();
}

TArray<EDirection> AATile::GetConnectorCorruptedDirections() const {
    return TArray<EDirection>();
}

AActor* AATile::GetConnector(EDirection Direction) const {
    return NULL;
}

bool AATile::GetAllDoorsAreRegistered() const {
    return false;
}

TArray<AADoor*> AATile::GetAllDoors() const {
    return TArray<AADoor*>();
}

void AATile::GetAllComponentsFromTile(TSubclassOf<UActorComponent> ComponentClass, TArray<UActorComponent*>& OutComponents) const {
}

void AATile::GetAllChildActorsFromTile(TSubclassOf<AActor> ActorClass, TArray<AActor*>& OutActors) const {
}

TArray<UChildActorComponent*> AATile::GetAllChildActorComponentsFromTile(TSubclassOf<AActor> ActorClass) const {
    return TArray<UChildActorComponent*>();
}

TMap<EDirection, AATile*> AATile::GetAdjacentTilesByRotatedDirections() const {
    return TMap<EDirection, AATile*>();
}

AATile* AATile::GetAdjacentTileByRotatedDirection(EDirection Direction) const {
    return NULL;
}

void AATile::DestroyAllDoors() {
}


