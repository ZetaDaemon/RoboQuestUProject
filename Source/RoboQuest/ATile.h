#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=HitResult -FallbackName=HitResult
#include "Components/ArrowComponent.h"
#include "ConnectorTemplate.h"
#include "EDirection.h"
#include "EForceTileDirection.h"
#include "EMultiplayerLoot.h"
#include "ESplineType.h"
#include "ETileType.h"
#include "Templates/SubclassOf.h"
#include "ATile.generated.h"

class AADoor;
class AAGameMode;
class AAGameState;
class AAJumpad;
class AALevelGenerator;
class AALightSelector;
class AAMax;
class AAPlayerController;
class AASquadPoint;
class AATile;
class ACharacter_Player;
class UAGameInstance;
class UActorComponent;
class UArrowComponent;
class UBoxComponent;
class UChildActorComponent;
class UPrimitiveComponent;
class USceneComponent;
class UStaticMeshComponent;
class UTexture2D;

UCLASS(Abstract, Blueprintable)
class ROBOQUEST_API AATile : public AActor {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateOnCleanUpTile);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateOnAllOrderableActorsAreRegistered);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnAllDoorsAreRegistered, AATile*, Tile);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* SceneRoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UChildActorComponent* EnvTile;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UArrowComponent* Arrow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETileType Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 SidePathID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName PathLevelRowName;
    
protected:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AATile* AdjacentTiles[4];
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EForceTileDirection ForceTileEnteringDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EForceTileDirection ForceTileExitingDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EDirection> ForceOpenedConnectors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<AActor>> ActorClassesToDestroyOnCleanUp;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> ActorsToDestroyOnCleanUp;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AADoor*> DoorsToIgnoreOnCleanUp;
    
private:
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* OpenedConnectorsTexture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* ClosedConnectorsTexture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* MaskTexture;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* RoofSpawned;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoxComponent* InvisibleWall;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* InvisibleWallVisualizer;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FConnectorTemplate ConnectorsTemplate[4];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OffsetLookAtCity;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> HoleSpawners;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FName, EMultiplayerLoot> MultiplayerLootByID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> PlayerLootSpawned;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> LevelLootSpawned;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FName> MerchantsAlreadySpawnedAndExcluded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> DiggingHolesSpawned;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AASquadPoint*> SquadPointsToIgnore;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoxComponent* OverlapBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OverlapBoxSizeOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OverrideOverlapBoxSizeZ;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowMirror;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bForceMirror;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NavMeshHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NavMeshOffsetZ;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AADoor*> AllDoors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AADoor*> EnteringDoors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AADoor*> ExitingDoorsToMainPath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AADoor*> ExitingDoorsToSidePath;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> OrderableActors;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AAJumpad*> Jumpads;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> StoryCapsulesSpawned;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> CodeActors;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FName MaxTextRowName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAMax* SpawnedMax;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAPlayerController* LocalPlayerControllerRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACharacter_Player* LocalPlayerCharacterRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AALevelGenerator* LevelGeneratorRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAGameState* GameStateRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AALightSelector* LightSelectorRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAGameInstance* GameInstanceRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAGameMode* GameModeRef;
    
public:
    AATile(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void RandomizeMeshes();
    
    UFUNCTION(BlueprintCallable)
    void OnStorySlotDestroyed(AActor* Actor);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnReplicatedActorDestroyed(AActor* Actor);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnLootSpawnedDestroyed(AActor* Actor);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnDoorDestroyed(AActor* Actor);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintReplicatedActorRegistered(AActor* ReplicatedActor);
    
    UFUNCTION(BlueprintCallable)
    void OnBeginTileOverlap(UPrimitiveComponent* OverlappedComp, AActor* OverlappingActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetReplicatedActorsByClass(TSubclassOf<AActor> ActorClass, TArray<AActor*>& OutActors) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<AActor*> GetLootSpawnedByType(FName LootType) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AAPlayerController* GetLocalPlayerControllerRef() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ACharacter_Player* GetLocalPlayerCharacterRef() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AALightSelector* GetLightSelectorRef() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AALevelGenerator* GetLevelGeneratorRef() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AAGameState* GetGameStateRef() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AAGameMode* GetGameModeRef();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<AADoor*> GetExitingDoorsToSidePath() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<AADoor*> GetExitingDoorsToMainPath() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<AADoor*> GetExitingDoors() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<AADoor*> GetEnteringDoors() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EDirection GetEnteringDirection() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetEnemyLevel() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<EDirection> GetConnectorOpenedDirections() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<EDirection> GetConnectorCorruptedDirections() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetConnector(EDirection Direction) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetAllDoorsAreRegistered() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<AADoor*> GetAllDoors() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetAllComponentsFromTile(TSubclassOf<UActorComponent> ComponentClass, TArray<UActorComponent*>& OutComponents) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetAllChildActorsFromTile(TSubclassOf<AActor> ActorClass, TArray<AActor*>& OutActors) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UChildActorComponent*> GetAllChildActorComponentsFromTile(TSubclassOf<AActor> ActorClass) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TMap<EDirection, AATile*> GetAdjacentTilesByRotatedDirections() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AATile* GetAdjacentTileByRotatedDirection(EDirection Direction) const;
    
    UFUNCTION(BlueprintCallable)
    void DestroyAllDoors();
    
};

