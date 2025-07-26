#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "AEndTile.h"
#include "EDoorState.h"
#include "ACorruptedEndTile.generated.h"

class AADoor;
class AAInteractiveBomb;
class AAInteractiveCrystal;
class ACharacter_Player;

UCLASS(Blueprintable)
class ROBOQUEST_API AACorruptedEndTile : public AAEndTile {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAInteractiveBomb* InteractiveBombRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAInteractiveCrystal* InteractiveCrystalRef;
    
public:
    AACorruptedEndTile(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void SafetyForceOpenCrystalDoor(ACharacter_Player* Player);
    
    UFUNCTION(BlueprintCallable)
    void OnTimeElapsed();
    
    UFUNCTION(BlueprintCallable)
    void OnTileValidated();
    
    UFUNCTION(BlueprintCallable)
    void OnPlayerStartEnteringExitingDoor(AADoor* Door, ACharacter_Player* Player);
    
    UFUNCTION(BlueprintCallable)
    void OnExitingDoorCrossedByPlayer(AADoor* Door, ACharacter_Player* Player, const FVector& Forward);
    
    UFUNCTION(BlueprintCallable)
    void OnExitingDoorClosed(AADoor* Door, EDoorState NewState);
    
    UFUNCTION(BlueprintCallable)
    void OnEnteringDoorOpened(AADoor* Door, EDoorState NewState);
    
};

