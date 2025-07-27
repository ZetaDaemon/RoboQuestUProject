#pragma once
#include "CoreMinimal.h"
#include "TextureSubsettings.generated.h"

USTRUCT(BlueprintType)
struct FTextureSubsettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxAnisotropy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 StreamingPoolSize;
    
    ROBOQUEST_API FTextureSubsettings();
};

