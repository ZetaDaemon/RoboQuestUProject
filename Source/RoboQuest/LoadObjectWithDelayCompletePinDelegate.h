#pragma once
#include "CoreMinimal.h"
#include "LoadObjectWithDelayCompletePinDelegate.generated.h"

class UObject;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FLoadObjectWithDelayCompletePin, UObject*, Object, int64, LoadingTime);

