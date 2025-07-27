#pragma once
#include "CoreMinimal.h"
#include "LoadObjectForUICompletePinDelegate.generated.h"

class UObject;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FLoadObjectForUICompletePin, UObject*, Object, int64, LoadingTime);

