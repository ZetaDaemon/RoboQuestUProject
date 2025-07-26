#pragma once
#include "CoreMinimal.h"
#include "LevelRowHandle.h"
#include "OverrideStarsByPCPercent.generated.h"

USTRUCT(BlueprintType)
struct FOverrideStarsByPCPercent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLevelRowHandle Level;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 StarsByPCPercent[5];
    
    ROBOQUEST_API FOverrideStarsByPCPercent();
};

