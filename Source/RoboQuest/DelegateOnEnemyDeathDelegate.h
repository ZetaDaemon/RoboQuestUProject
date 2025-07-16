#pragma once
#include "CoreMinimal.h"
#include "RQDamageInfo.h"
#include "DelegateOnEnemyDeathDelegate.generated.h"

class ACharacter_Enemy;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateOnEnemyDeath, ACharacter_Enemy*, EnemyRef, FRQDamageInfo, DamageInfo);

