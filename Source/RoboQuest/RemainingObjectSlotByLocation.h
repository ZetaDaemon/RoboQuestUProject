#pragma once
#include "CoreMinimal.h"
#include "RemainingObjectSlotByLocation.generated.h"

class AAObjectSlot;

USTRUCT(BlueprintType)
struct FRemainingObjectSlotByLocation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAObjectSlot* ObjectSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 LocationInt;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 RemainingCount;
    
    ROBOQUEST_API FRemainingObjectSlotByLocation();
};

