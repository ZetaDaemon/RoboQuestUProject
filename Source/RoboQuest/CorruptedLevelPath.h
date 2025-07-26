#pragma once
#include "CoreMinimal.h"
#include "ETileType.h"
#include "LevelRowHandle.h"
#include "CorruptedLevelPath.generated.h"

class UCurveFloat;

USTRUCT(BlueprintType)
struct FCorruptedLevelPath {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLevelRowHandle CorruptedLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* CompletionTimeCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LevelXP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETileType Location;
    
    ROBOQUEST_API FCorruptedLevelPath();
};

