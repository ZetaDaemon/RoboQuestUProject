#pragma once
#include "CoreMinimal.h"
#include "ControllerICon.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct FControllerICon {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* Icons[4];
    
    ROBOQUEST_API FControllerICon();
};

