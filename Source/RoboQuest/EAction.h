#pragma once
#include "CoreMinimal.h"
#include "EAction.generated.h"

UENUM(BlueprintType)
enum class EAction : uint8 {
    PrimaryFire,
    SecondaryFire,
    Reload,
    Sprint,
    Bash,
    Switch,
    Crouch,
    Jump,
    Interract,
    Throw,
    Map,
    Menu,
    ClassSkill,
    Move,
    UI,
    Look,
    None,
    PowerSlide,
    Dash,
    Ping,
    PerkSelector,
    LastIndex,
};

