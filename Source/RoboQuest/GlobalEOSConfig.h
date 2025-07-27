#pragma once
#include "CoreMinimal.h"
#include "GlobalEOSConfig.generated.h"

USTRUCT(BlueprintType)
struct FGlobalEOSConfig {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Platform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanCrossPlatform;
    
    ROBOQUEST_API FGlobalEOSConfig();
};

