#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "WeaponRowHandle.generated.h"

USTRUCT(BlueprintType)
struct FWeaponRowHandle : public FDataTableRowHandle {
    GENERATED_BODY()
public:
    ROBOQUEST_API FWeaponRowHandle();
};

