#pragma once
#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=AssetManager -FallbackName=AssetManager
#include "AAssetManager.generated.h"

UCLASS(Blueprintable)
class ROBOQUEST_API UAAssetManager : public UAssetManager {
    GENERATED_BODY()
public:
    UAAssetManager();

};

