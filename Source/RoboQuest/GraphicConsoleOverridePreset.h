#pragma once
#include "CoreMinimal.h"
#include "GraphicConsoleOverrideSettings.h"
#include "GraphicConsoleOverridePreset.generated.h"

USTRUCT(BlueprintType)
struct FGraphicConsoleOverridePreset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGraphicConsoleOverrideSettings OverrideSettings;
    
    ROBOQUEST_API FGraphicConsoleOverridePreset();
};

