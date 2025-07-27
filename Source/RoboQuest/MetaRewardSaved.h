#pragma once
#include "CoreMinimal.h"
#include "MetaRewardSaved.generated.h"

USTRUCT(BlueprintType)
struct FMetaRewardSaved {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> EntryLevel;
    
    ROBOQUEST_API FMetaRewardSaved();
};

