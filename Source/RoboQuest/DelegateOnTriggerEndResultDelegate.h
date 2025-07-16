#pragma once
#include "CoreMinimal.h"
#include "RQHitResult.h"
#include "DelegateOnTriggerEndResultDelegate.generated.h"

class AAProjectile;
class UASkill;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDelegateOnTriggerEndResult, UASkill*, Skill, FRQHitResult, RQHitResult, AAProjectile*, Projectile);

