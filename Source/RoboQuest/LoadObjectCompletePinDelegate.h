#pragma once
#include "CoreMinimal.h"
#include "LoadObjectCompletePinDelegate.generated.h"

class UObject;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FLoadObjectCompletePin, UObject*, Object, int64, LoadingTime);

