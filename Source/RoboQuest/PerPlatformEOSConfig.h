#pragma once
#include "CoreMinimal.h"
#include "GlobalEOSConfig.h"
#include "PerPlatformEOSConfig.generated.h"

USTRUCT(BlueprintType)
struct FPerPlatformEOSConfig {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGlobalEOSConfig> PlatformConfigs;
    
    ROBOQUEST_API FPerPlatformEOSConfig();
};

