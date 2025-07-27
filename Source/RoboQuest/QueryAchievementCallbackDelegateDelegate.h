#pragma once
#include "CoreMinimal.h"
#include "AchievementsArray.h"
#include "QueryAchievementCallbackDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FQueryAchievementCallbackDelegate, const TArray<FName>&, SuccessfulSubsystem, const TArray<FAchievementsArray>&, AchievementsStruct);

