#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Interface -FallbackName=Interface
#include "EAction.h"
#include "ISkillWarmup.generated.h"

UINTERFACE(Blueprintable, MinimalAPI)
class UISkillWarmup : public UInterface {
    GENERATED_BODY()
};

class IISkillWarmup : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetSkillWarmupRatio(float NewRatio, EAction TargetSkill);
    
};

