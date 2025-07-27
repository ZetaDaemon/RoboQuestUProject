#pragma once
#include "CoreMinimal.h"
#include "BlueprintAchievement.h"
#include "BlueprintAchievementMap.generated.h"

USTRUCT(BlueprintType)
struct FBlueprintAchievementMap {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FBlueprintAchievement> AchievementMap;
    
    ROBOQUEST_API FBlueprintAchievementMap();
};

