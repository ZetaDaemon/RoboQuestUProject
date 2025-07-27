#pragma once
#include "CoreMinimal.h"
#include "AInteractive.h"
#include "CollectableRowHandle.h"
#include "AInteractiveReward.generated.h"

UCLASS(Blueprintable)
class ROBOQUEST_API AAInteractiveReward : public AAInteractive {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCollectableRowHandle Collectable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText ItemName;
    
    AAInteractiveReward(const FObjectInitializer& ObjectInitializer);

};

