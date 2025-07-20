#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Interface -FallbackName=Interface
#include "EAction.h"
#include "Templates/SubclassOf.h"
#include "ISkillManager.generated.h"

class UASkill;
class UASkillManager;

UINTERFACE(BlueprintType, meta=(CannotImplementInterfaceInBlueprint))
class UISkillManager : public UInterface {
    GENERATED_BODY()
};

class IISkillManager : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable)
    virtual void PressedSkill(EAction Action) PURE_VIRTUAL(PressedSkill,);
    
    UFUNCTION(BlueprintCallable)
    virtual TArray<UASkill*> GetSkills() const PURE_VIRTUAL(GetSkills, return TArray<UASkill*>(););
    
    UFUNCTION(BlueprintCallable)
    virtual UASkillManager* GetSkillManager() PURE_VIRTUAL(GetSkillManager, return NULL;);
    
    UFUNCTION(BlueprintCallable)
    virtual UASkill* GetSkillByClass(TSubclassOf<UASkill> SkillClass) PURE_VIRTUAL(GetSkillByClass, return NULL;);
    
    UFUNCTION(BlueprintCallable)
    virtual UASkill* GetSkill(EAction Action) PURE_VIRTUAL(GetSkill, return NULL;);
    
    UFUNCTION(BlueprintCallable)
    virtual TArray<UASkill*> GetCurrentSkills() PURE_VIRTUAL(GetCurrentSkills, return TArray<UASkill*>(););
    
};

