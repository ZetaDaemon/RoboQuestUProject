#pragma once
#include "CoreMinimal.h"
#include "DynamicTexture.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct FDynamicTexture {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UTexture2D* Texture2D;
    
public:
    ROBOQUEST_API FDynamicTexture();
};

