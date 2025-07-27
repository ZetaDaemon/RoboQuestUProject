#pragma once
#include "CoreMinimal.h"
#include "LoadObjectFromPathCompletePinDelegate.generated.h"

class UObject;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FLoadObjectFromPathCompletePin, UObject*, Object, int64, LoadingTime);

