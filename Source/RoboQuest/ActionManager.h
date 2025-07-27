#pragma once
#include "CoreMinimal.h"
#include "ActionProperty.h"
#include "ActionManager.generated.h"

USTRUCT(BlueprintType)
struct FActionManager {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FActionProperty ActionProperties[21];
    
    ROBOQUEST_API FActionManager();
};

