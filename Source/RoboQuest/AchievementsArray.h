#pragma once
#include "CoreMinimal.h"
#include "BlueprintAchievement.h"
#include "AchievementsArray.generated.h"

USTRUCT(BlueprintType)
struct FAchievementsArray {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName OSSName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FBlueprintAchievement> Achievements;
    
    ROBOQUEST_API FAchievementsArray();
};

