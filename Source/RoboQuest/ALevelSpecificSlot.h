#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include "LevelRowHandle.h"
#include "ALevelSpecificSlot.generated.h"

class USceneComponent;

UCLASS(Blueprintable)
class ROBOQUEST_API AALevelSpecificSlot : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLevelRowHandle> ActivatedInLevels;
    
    AALevelSpecificSlot(const FObjectInitializer& ObjectInitializer);

};

