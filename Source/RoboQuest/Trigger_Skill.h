#pragma once
#include "CoreMinimal.h"
#include "ATrigger.h"
#include "DelegateOnTriggerSkillDelegate.h"
#include "Trigger_Skill.generated.h"

class AAWeapon;
class ACharacter_AI;
class ACharacter_Player;
class UASkill;

UCLASS(Blueprintable)
class ROBOQUEST_API UTrigger_Skill : public UATrigger {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnTriggerSkill DelegateOnTriggerSkill;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ACharacter_Player* PlayerCharacter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 GameplayTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlyWeaponSkill;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAWeapon* TriggerWeapon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UASkill*> CurrentSkillTriggers;
    
    UTrigger_Skill();

    UFUNCTION(BlueprintCallable)
    void OnWeaponChange(AAWeapon* NewWeapon);
    
    UFUNCTION(BlueprintCallable)
    void OnUpdateSkillTag(UASkill* NewSkill);
    
    UFUNCTION(BlueprintCallable)
    void OnSpawnSomeone(ACharacter_AI* SpawnedCharacter, bool bIsStart);
    
    UFUNCTION(BlueprintCallable)
    void OnAddSkill(UASkill* NewSkill);
    
};

