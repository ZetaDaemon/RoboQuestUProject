#pragma once
#include "CoreMinimal.h"
#include "DelegateOnFocusActorDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnFocusActor, AActor*, InFocusedActor);

