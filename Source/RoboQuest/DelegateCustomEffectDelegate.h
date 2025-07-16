#pragma once
#include "CoreMinimal.h"
#include "NetworkSkillInfo.h"
#include "DelegateCustomEffectDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateCustomEffect, FNetworkSkillInfo, NetworkInfo);

