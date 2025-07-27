#pragma once
#include "CoreMinimal.h"
#include "ReadPlayerDataStorageFileDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FReadPlayerDataStorageFileDelegate, bool, bSuccess, const FString&, Filename, const TArray<uint8>&, Bytes);

