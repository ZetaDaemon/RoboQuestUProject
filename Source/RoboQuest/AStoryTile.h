#pragma once
#include "CoreMinimal.h"
#include "ATile.h"
#include "EDoorState.h"
#include "AStoryTile.generated.h"

class AADoor;
class AALavaTrap;

UCLASS(Blueprintable)
class ROBOQUEST_API AAStoryTile : public AATile {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AALavaTrap*> LavaTraps;
    
public:
    AAStoryTile(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnSafeZoneDoorStateChanged(AADoor* Door, EDoorState NewState);
    
};

