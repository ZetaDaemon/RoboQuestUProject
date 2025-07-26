#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Interface -FallbackName=Interface
#include "ITileReplicatedActor.generated.h"

class AATile;
class AActor;
class USceneComponent;

UINTERFACE(BlueprintType, meta=(CannotImplementInterfaceInBlueprint))
class UITileReplicatedActor : public UInterface {
    GENERATED_BODY()
};

class IITileReplicatedActor : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable)
    virtual AATile* GetSlotParentTile() const PURE_VIRTUAL(GetSlotParentTile, return NULL;);
    
    UFUNCTION(BlueprintCallable)
    virtual AActor* GetSlotParentActor() const PURE_VIRTUAL(GetSlotParentActor, return NULL;);
    
    UFUNCTION(BlueprintCallable)
    virtual USceneComponent* GetSlotComponent() const PURE_VIRTUAL(GetSlotComponent, return NULL;);
    
};

