#pragma once
#include "CoreMinimal.h"
#include "DelegateOnTriggerSkillDelegate.generated.h"

class UASkill;
class UATrigger;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDelegateOnTriggerSkill, UATrigger*, Trigger, UASkill*, Skill, bool, bIsTriggered);

