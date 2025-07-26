#pragma once
#include "CoreMinimal.h"
#include "ATile.h"
#include "EDoorState.h"
#include "Templates/SubclassOf.h"
#include "AStartTile.generated.h"

class AAChest;
class AADoor;
class AAInteractiveWeapon;
class AALavaTrap;
class AAWeapon;
class AActor;

UCLASS(Abstract, Blueprintable)
class ROBOQUEST_API AAStartTile : public AATile {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateStartDoorIsClosed);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateHasRegisteredAllLoot);
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AALavaTrap* CorruptedLavaTrap;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AAChest*> RegisteredChests;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AAInteractiveWeapon*> RegisteredWeaponLoot;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<AAWeapon>> WeaponsNotAllowedInPool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateStartDoorIsClosed DelegateStartDoorIsClosed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<AActor>> ActorClassesToDestroyOnStartDoorClosed;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> ActorsToDestroyOnStartDoorClosed;
    
public:
    AAStartTile(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnStartDoorStateChanged(AADoor* Door, EDoorState NewState);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnChestHasRegisteredAllLoot();
    
    UFUNCTION(BlueprintCallable)
    void OnChestDestroyed(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void DelayedNotifyStartDoorIsClosed(AADoor* ClosedDoor);
    
};

