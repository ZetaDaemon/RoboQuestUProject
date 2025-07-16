#pragma once
#include "CoreMinimal.h"
#include "DelegateOnRidingSplineDelegate.generated.h"

class AASpline;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateOnRidingSpline, AASpline*, Spline, bool, bIsStart);

