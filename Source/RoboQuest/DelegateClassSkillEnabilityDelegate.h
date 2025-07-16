#pragma once
#include "CoreMinimal.h"
#include "DelegateClassSkillEnabilityDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateClassSkillEnability, bool, bEnable);

