#pragma once
#include "CoreMinimal.h"
#include "Modifier_Stat_Scale.h"
#include "Modifier_Stat_Scale_Weapon.generated.h"

class AAWeapon;

UCLASS(Blueprintable)
class ROBOQUEST_API UModifier_Stat_Scale_Weapon : public UModifier_Stat_Scale {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AAWeapon* WeaponRef;
    
    UModifier_Stat_Scale_Weapon();

};

