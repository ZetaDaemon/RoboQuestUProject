#pragma once
#include "CoreMinimal.h"
#include "EStunArrowDirection.h"
#include "InputKey.h"
#include "InputKeyWithDirection.generated.h"

USTRUCT(BlueprintType)
struct FInputKeyWithDirection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInputKey Key;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EStunArrowDirection Direction;
    
    ROBOQUEST_API FInputKeyWithDirection();
};

