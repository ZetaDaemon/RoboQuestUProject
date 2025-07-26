#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=HitResult -FallbackName=HitResult
#include "ATile.h"
#include "EDoorState.h"
#include "RQDamageInfo.h"
#include "Templates/SubclassOf.h"
#include "ASpecialTile.generated.h"

class AAChest;
class AADoor;
class AASpecialSpawner;
class AATrap;
class AActor;
class ACharacter_Player;
class UPrimitiveComponent;
class USpecialTriggerBoxComponent;

UCLASS(Blueprintable)
class ROBOQUEST_API AASpecialTile : public AATile {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<USpecialTriggerBoxComponent*> TriggerBoxes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> InteriorClassToSpawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* InteriorTileRef;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowInteriorMirrored;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInteriorMirrored;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AAChest*> PendingChests;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NavMeshSizeY;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AATrap*> Traps;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> SpecialElements;
    
public:
    AASpecialTile(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void RegisterChest(AAChest* Chest);
    
private:
    UFUNCTION(BlueprintCallable)
    void OpenNextChest();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnSpecialDoorOpenedAfterValidated(AADoor* Door, EDoorState NewState);
    
    UFUNCTION(BlueprintCallable)
    void OnSpecialDoorOpened(AADoor* Door, EDoorState NewState);
    
    UFUNCTION(BlueprintCallable)
    void OnSpecialDoorCrossedByPlayer(AADoor* Door, ACharacter_Player* Player, const FVector& ExitingForward);
    
    UFUNCTION(BlueprintCallable)
    void OnSpecialDoorClosed(AADoor* Door, EDoorState NewState);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnSpawnedEnemyDeath(AASpecialSpawner* SpecialSpawner, int32 DeadWaveID);
    
    UFUNCTION(BlueprintCallable)
    void OnPlayerDisconnected(ACharacter_Player* DisconnectedPlayer);
    
    UFUNCTION(BlueprintCallable)
    void OnPlayerDied(const FRQDamageInfo& DamageInfo);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnEnterExitingJumpad();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnEndTriggerOverlap(UPrimitiveComponent* OverlappedComp, AActor* OverlappedActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintValidateTile();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintSpecialDoorOpened();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnBeginTriggerOverlap(UPrimitiveComponent* OverlappedComp, AActor* OverlappingActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetInteriorTile() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetAllChildActorsFromInteriorTile(TSubclassOf<AActor> ActorClass, TArray<AActor*>& OutActors) const;
    
};

