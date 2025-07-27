#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TableRowBase -FallbackName=TableRowBase
#include "Engine/DataTable.h"
#include "WeaponAffixRowHandle.h"
#include "WeaponAffixBunlde.generated.h"

USTRUCT(BlueprintType)
struct FWeaponAffixBunlde : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWeaponAffixRowHandle> Affixes;
    
    ROBOQUEST_API FWeaponAffixBunlde();
};

