#pragma once
#include "CoreMinimal.h"
#include "BlueprintUserStats.generated.h"

USTRUCT(BlueprintType)
struct FBlueprintUserStats {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, int32> StatsInt;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, float> StatsFloat;
    
    ROBOQUEST_API FBlueprintUserStats();
};

