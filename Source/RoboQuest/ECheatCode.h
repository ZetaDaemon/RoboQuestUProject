#pragma once
#include "CoreMinimal.h"
#include "ECheatCode.generated.h"

UENUM(BlueprintType)
enum class ECheatCode : uint8 {
    PlayerInvulnerability,
    EnemyInvulnerability,
    InfiniteRagdoll,
    InfiniteClip,
    NoCooldown,
    GhostMod,
    GodMod,
    SuperSprint,
    RevealMap,
    GamepadDebug,
    DisableGamepadAssist,
    AimDebug,
    HardMode,
    RecordMode,
    DebugMovement,
    MouseMagnetisme,
};

