#pragma once
#include "CoreMinimal.h"
#include "WeaponSpecificHandPose.generated.h"

class UAnimSequence;

USTRUCT(BlueprintType)
struct FWeaponSpecificHandPose {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimSequence* Left;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimSequence* Right;
    
    ROBOQUEST_API FWeaponSpecificHandPose();
};

