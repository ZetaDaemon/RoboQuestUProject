#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "ATile.h"
#include "EDoorState.h"
#include "AWallTile.generated.h"

class AADoor;
class ACharacter_Player;

UCLASS(Blueprintable)
class ROBOQUEST_API AAWallTile : public AATile {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<ACharacter_Player*> PlayersInside;
    
public:
    AAWallTile(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnSafeZoneDoorStateChanged(AADoor* Door, EDoorState NewState);
    
    UFUNCTION(BlueprintCallable)
    void OnDoorCrossedByPlayer(AADoor* Door, ACharacter_Player* Player, const FVector& ExitingForward);
    
};

