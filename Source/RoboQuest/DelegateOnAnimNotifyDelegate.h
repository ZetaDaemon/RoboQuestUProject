#pragma once
#include "CoreMinimal.h"
#include "DelegateOnAnimNotifyDelegate.generated.h"

class UAPlayerSkill;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnAnimNotify, UAPlayerSkill*, Skill);

