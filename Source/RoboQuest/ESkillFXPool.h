#pragma once
#include "CoreMinimal.h"
#include "ESkillFXPool.generated.h"

UENUM(BlueprintType)
enum class ESkillFXPool : uint8 {
    RaycastTrail,
    BouncingRaycastTrail,
    ImpactFX,
    SurfaceFX,
    MuzzleFX,
    PreshootFX,
    BeamFX,
    Others,
    LastIndex,
};

