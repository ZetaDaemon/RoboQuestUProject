#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TableRowBase -FallbackName=TableRowBase
#include "WeaponAffixRow.h"
#include "WeaponAffix.generated.h"

USTRUCT(BlueprintType)
struct FWeaponAffix : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeaponAffixRow Affix;
    
    ROBOQUEST_API FWeaponAffix();
};

