#pragma once
#include "CoreMinimal.h"
#include "DelegateOnInteractDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnInteract, AActor*, InteractActor);

