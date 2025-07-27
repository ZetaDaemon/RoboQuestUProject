#pragma once
#include "CoreMinimal.h"
#include "RecapMutator.generated.h"

USTRUCT(BlueprintType)
struct FRecapMutator {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName MutatorName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> UpgradeNames;
    
    ROBOQUEST_API FRecapMutator();
};

