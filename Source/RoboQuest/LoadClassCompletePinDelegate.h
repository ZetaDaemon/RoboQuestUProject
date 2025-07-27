#pragma once
#include "CoreMinimal.h"
#include "LoadClassCompletePinDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FLoadClassCompletePin, UClass*, Class, int64, LoadingTime);

