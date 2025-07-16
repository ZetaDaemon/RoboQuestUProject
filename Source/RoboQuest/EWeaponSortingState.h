#pragma once
#include "CoreMinimal.h"
#include "EWeaponSortingState.generated.h"

UENUM(BlueprintType)
enum class EWeaponSortingState : uint8 {
    None,
    Favorite,
    Exclude,
};

