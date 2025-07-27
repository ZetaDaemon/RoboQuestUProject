#pragma once
#include "CoreMinimal.h"
#include "BasecampObjectSlots.generated.h"

class AAObjectSlot;

USTRUCT(BlueprintType)
struct FBasecampObjectSlots {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AAObjectSlot*> ObjectSlots;
    
    ROBOQUEST_API FBasecampObjectSlots();
};

