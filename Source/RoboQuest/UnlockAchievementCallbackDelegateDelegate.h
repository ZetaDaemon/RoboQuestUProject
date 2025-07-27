#pragma once
#include "CoreMinimal.h"
#include "UnlockAchievementCallbackDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUnlockAchievementCallbackDelegate, const TArray<FName>&, SuccessfulSubsystem);

