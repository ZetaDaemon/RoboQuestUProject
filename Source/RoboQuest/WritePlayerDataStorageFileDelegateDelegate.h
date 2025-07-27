#pragma once
#include "CoreMinimal.h"
#include "WritePlayerDataStorageFileDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FWritePlayerDataStorageFileDelegate, bool, bSuccess, const FString&, Filename);

