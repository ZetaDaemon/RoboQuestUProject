#pragma once
#include "CoreMinimal.h"
#include "ATrap.h"
#include "EAction.h"
#include "ISkillManager.h"
#include "Templates/SubclassOf.h"
#include "ATrap_Skill.generated.h"

class UASkill;
class UASkillManager;

UCLASS(Blueprintable)
class ROBOQUEST_API AATrap_Skill : public AATrap, public IISkillManager {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UASkillManager* SkillManager;
    
    AATrap_Skill(const FObjectInitializer& ObjectInitializer);


    // Fix for true pure virtual functions not being implemented
    UFUNCTION(BlueprintCallable)
    void PressedSkill(EAction Action) override PURE_VIRTUAL(PressedSkill,);
    
    UFUNCTION(BlueprintCallable)
    TArray<UASkill*> GetSkills() const override PURE_VIRTUAL(GetSkills, return TArray<UASkill*>(););
    
    UFUNCTION(BlueprintCallable)
    UASkillManager* GetSkillManager() override PURE_VIRTUAL(GetSkillManager, return NULL;);
    
    UFUNCTION(BlueprintCallable)
    UASkill* GetSkillByClass(TSubclassOf<UASkill> SkillClass) override PURE_VIRTUAL(GetSkillByClass, return NULL;);
    
    UFUNCTION(BlueprintCallable)
    UASkill* GetSkill(EAction Action) override PURE_VIRTUAL(GetSkill, return NULL;);
    
    UFUNCTION(BlueprintCallable)
    TArray<UASkill*> GetCurrentSkills() override PURE_VIRTUAL(GetCurrentSkills, return TArray<UASkill*>(););
    
};

