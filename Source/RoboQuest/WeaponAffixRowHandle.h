#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DataTableRowHandle -FallbackName=DataTableRowHandle
#include "WeaponAffixRowHandle.generated.h"

USTRUCT(BlueprintType)
struct FWeaponAffixRowHandle : public FDataTableRowHandle {
    GENERATED_BODY()
public:
    ROBOQUEST_API FWeaponAffixRowHandle();
};

