#pragma once
#include "CoreMinimal.h"
#include "LevelAreaIDAndXP.generated.h"

USTRUCT(BlueprintType)
struct FLevelAreaIDAndXP {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<uint8> AreaIDs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float XP;
    
    ROBOQUEST_API FLevelAreaIDAndXP();
};

