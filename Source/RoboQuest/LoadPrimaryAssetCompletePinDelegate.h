#pragma once
#include "CoreMinimal.h"
#include "LoadPrimaryAssetCompletePinDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLoadPrimaryAssetCompletePin, int64, LoadingTime);

