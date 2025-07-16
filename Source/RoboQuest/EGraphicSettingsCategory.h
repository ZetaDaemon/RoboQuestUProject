#pragma once
#include "CoreMinimal.h"
#include "EGraphicSettingsCategory.generated.h"

UENUM(BlueprintType)
enum class EGraphicSettingsCategory : uint8 {
    Texture,
    Anisotropy,
    AA,
    Shadow,
    Occlusion,
    Effect,
    PostProcess,
    Ragdoll,
    MAX,
};

