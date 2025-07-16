#pragma once
#include "CoreMinimal.h"
#include "EquippedWeapon.generated.h"

class AAInteractiveWeapon;
class AAWeapon;

USTRUCT(BlueprintType)
struct FEquippedWeapon {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAWeapon* Weapon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAInteractiveWeapon* InteractiveWeapon;
    
    ROBOQUEST_API FEquippedWeapon();
};

