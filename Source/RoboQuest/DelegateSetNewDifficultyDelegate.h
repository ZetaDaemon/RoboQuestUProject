#pragma once
#include "CoreMinimal.h"
#include "DifficultyRow.h"
#include "DelegateSetNewDifficultyDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateSetNewDifficulty, const FName&, DifficultyRowName, const FDifficultyRow&, Difficulty);

