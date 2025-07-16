#pragma once
#include "CoreMinimal.h"
#include "WeaponAffixData.generated.h"

class UAWeaponAffix;

USTRUCT(BlueprintType)
struct FWeaponAffixData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> RowNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAWeaponAffix*> Affixes;
    
    ROBOQUEST_API FWeaponAffixData();
};

