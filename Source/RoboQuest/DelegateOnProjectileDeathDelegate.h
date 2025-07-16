#pragma once
#include "CoreMinimal.h"
#include "DelegateOnProjectileDeathDelegate.generated.h"

class AAProjectile;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnProjectileDeath, AAProjectile*, Projectile);

