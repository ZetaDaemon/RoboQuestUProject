#pragma once
#include "CoreMinimal.h"
#include "ATile.h"
#include "EDoorState.h"
#include "EElement.h"
#include "LevelRowHandle.h"
#include "ASasTile.generated.h"

class AADoor;
class AAElementalSwitcher;
class ACharacter_Player;

UCLASS(Abstract, Blueprintable)
class ROBOQUEST_API AASasTile : public AATile {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateExitingSasDoorIsClosed);
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FLevelRowHandle ForcePathByDirection[4];
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAElementalSwitcher* ElementalSwitcherRef;
    
public:
    AASasTile(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void OnSwitchElement(EElement NewElement);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnPlayerStartEnteringSafeZoneDoor(AADoor* Door, ACharacter_Player* Player);
    
    UFUNCTION(BlueprintCallable)
    void OnExitingSafeZoneDoorToMainOrSidePathOpened(AADoor* Door, EDoorState NewState);
    
    UFUNCTION(BlueprintCallable)
    void OnExitingSafeZoneDoorToMainOrSidePathClosed(AADoor* Door, EDoorState NewState);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnEnteringSafeZoneDoorStateChanged(AADoor* Door, EDoorState NewState);
    
    UFUNCTION(BlueprintCallable)
    void DelayedNotifySasDoorIsClosed(AADoor* ClosedDoor);
    
};

