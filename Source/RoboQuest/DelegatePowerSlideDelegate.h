#pragma once
#include "CoreMinimal.h"
#include "DelegatePowerSlideDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegatePowerSlide, bool, bIsStart);

