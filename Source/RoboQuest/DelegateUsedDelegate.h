#pragma once
#include "CoreMinimal.h"
#include "DelegateUsedDelegate.generated.h"

class UASkill;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateUsed, UASkill*, Skill, bool, bIsStarting);

