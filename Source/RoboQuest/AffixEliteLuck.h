#pragma once
#include "CoreMinimal.h"
#include "AffixEliteLuck.generated.h"

USTRUCT(BlueprintType)
struct FAffixEliteLuck {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> AffixEliteLuck;
    
    ROBOQUEST_API FAffixEliteLuck();
};

