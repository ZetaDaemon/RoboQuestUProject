#pragma once
#include "CoreMinimal.h"
#include "EquippedWeapon.generated.h"

class AAWeapon;

USTRUCT(BlueprintType)
struct FEquippedWeapon {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAWeapon* Weapon;
    
    ROBOQUEST_API FEquippedWeapon();
};

