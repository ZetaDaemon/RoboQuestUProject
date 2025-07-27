#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=PrimaryDataAsset -FallbackName=PrimaryDataAsset
#include "CinematicBubbles.h"
#include "CinematicBubblesDataAsset.generated.h"

UCLASS(Blueprintable)
class ROBOQUEST_API UCinematicBubblesDataAsset : public UPrimaryDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCinematicBubbles> Bubbles;
    
    UCinematicBubblesDataAsset();

};

