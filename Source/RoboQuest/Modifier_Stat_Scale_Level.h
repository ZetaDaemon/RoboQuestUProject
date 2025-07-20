#pragma once
#include "CoreMinimal.h"
#include "Modifier_Stat_Scale_Player.h"
#include "Modifier_Stat_Scale_Level.generated.h"

UCLASS(Blueprintable)
class ROBOQUEST_API UModifier_Stat_Scale_Level : public UModifier_Stat_Scale_Player {
    GENERATED_BODY()
public:
private:
    
public:
    UModifier_Stat_Scale_Level();

private:
    UFUNCTION(BlueprintCallable)
    void OnUpdateLevel(int32 Level);
    
};

