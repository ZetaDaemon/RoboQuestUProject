#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include "ETrapSlotLocation.h"
#include "ASpawnerSlot.generated.h"

class UBillboardComponent;
class USceneComponent;

UCLASS(Blueprintable)
class ROBOQUEST_API AASpawnerSlot : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBillboardComponent* Icon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETrapSlotLocation Location;
    
    AASpawnerSlot(const FObjectInitializer& ObjectInitializer);

};

