#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "ABossTile.h"
#include "ACorruptedBossTile.generated.h"

class AADoor;
class AAInteractiveCrystal;
class ACharacter_Player;

UCLASS(Blueprintable)
class ROBOQUEST_API AACorruptedBossTile : public AABossTile {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAInteractiveCrystal* InteractiveCrystalRef;
    
public:
    AACorruptedBossTile(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnExitingDoorCrossedByPlayer(AADoor* Door, ACharacter_Player* Player, const FVector& Forward);
    
};

