#pragma once
#include "CoreMinimal.h"
#include "NetworkSkillInfo.h"
#include "DelegateTriggerAreaEffectDelegate.generated.h"

class AAProjectile;
class UASkill;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDelegateTriggerAreaEffect, UASkill*, Skill, FNetworkSkillInfo, SKillInfo, AAProjectile*, Projectile);

