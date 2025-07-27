#pragma once
#include "CoreMinimal.h"
#include "AInteractive.h"
#include "Interactive_GambleGarry.generated.h"

UCLASS(Blueprintable)
class ROBOQUEST_API AInteractive_GambleGarry : public AAInteractive {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<float> UROVisibleDistanceFactorThesholds;
    
    AInteractive_GambleGarry(const FObjectInitializer& ObjectInitializer);

};

