#pragma once
#include "CoreMinimal.h"
#include "DelegateStartBehaviorDelegate.generated.h"

class UASkill;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateStartBehavior, UASkill*, Skill);

