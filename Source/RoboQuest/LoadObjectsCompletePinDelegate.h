#pragma once
#include "CoreMinimal.h"
#include "LoadObjectsCompletePinDelegate.generated.h"

class UObject;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FLoadObjectsCompletePin, const TArray<UObject*>&, Objects, int64, LoadingTime);

