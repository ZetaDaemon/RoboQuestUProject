#pragma once
#include "CoreMinimal.h"
#include "GraphicQuality.h"
#include "GraphicConsole.generated.h"

USTRUCT(BlueprintType)
struct FGraphicConsole {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FPSLimit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGraphicQuality DefaultQuality;
    
    ROBOQUEST_API FGraphicConsole();
};

