#pragma once
#include "CoreMinimal.h"
#include "DelegateUpdateSuperBashPowerCellDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateUpdateSuperBashPowerCell, int32, CurrentPowerCell);

