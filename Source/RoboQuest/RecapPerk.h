#pragma once
#include "CoreMinimal.h"
#include "RecapPerk.generated.h"

USTRUCT(BlueprintType)
struct FRecapPerk {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName PerkName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> UpgradeNames;
    
    ROBOQUEST_API FRecapPerk();
};

