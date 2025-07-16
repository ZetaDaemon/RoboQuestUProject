#pragma once
#include "CoreMinimal.h"
#include "DelegateTagUpdateDelegate.generated.h"

class UASkill;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateTagUpdate, UASkill*, Skill);

