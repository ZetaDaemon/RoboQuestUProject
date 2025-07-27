#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TableRowBase -FallbackName=TableRowBase
#include "Engine/DataTable.h"
#include "WeaponRow.h"
#include "Weapon.generated.h"

USTRUCT(BlueprintType)
struct FWeapon : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeaponRow Weapon;
    
    ROBOQUEST_API FWeapon();
};

