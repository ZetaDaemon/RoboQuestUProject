#pragma once
#include "CoreMinimal.h"
#include "DelegatePostUsedDelegate.generated.h"

class UASkill;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegatePostUsed, UASkill*, Skill);

