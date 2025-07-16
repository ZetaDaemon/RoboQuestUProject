#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "EAction.h"
#include "SkillInputBP.h"
#include "Templates/SubclassOf.h"
#include "ASkillManager.generated.h"

class AACharacter;
class UASkill;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROBOQUEST_API UASkillManager : public UActorComponent {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateSwapSkillInput);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateSkillUsed, UASkill*, Skill, bool, bIsStarting);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateSkillTagUpdate, UASkill*, Skill);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateSkillPostUsed, UASkill*, Skill);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateSkillNoCost, EAction, TargetAction);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateSkillCancel, EAction, TargetAction);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateSkillAvaibility, EAction, TargetAction);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateOnStackUpdate, EAction, TargetAction, int32, CurrentStack);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateOnSkillsLoaded);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateOnSkillAnimNotify);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnRemoveSkill, UASkill*, RemovedSkill);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnAddSkill, UASkill*, NewSkill);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateSkillUsed DelegateSkillUsed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateSkillPostUsed DelegateSkillPostUsed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnAddSkill DelegateOnAddSkill;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AACharacter* CharacterOwner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EAction, TSoftClassPtr<UASkill>> SoftSkillClasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSkillInputBP> SkillListBP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<UASkill>, UASkill*> SkillListByClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TMap<EAction, UASkill*> SkillListByAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UASkill*> CurrentSkill;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoLoadSkill;
    
    UASkillManager(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SwapSkillInput(EAction Action1, EAction Action2);
    
    UFUNCTION(BlueprintCallable)
    void RemoveSkillInput(EAction Action);
    
    UFUNCTION(BlueprintCallable)
    void RemoveSkill(TSubclassOf<UASkill> NewSkill);
    
    UFUNCTION(BlueprintCallable)
    void OnNotifySkillUsed(UASkill* Skill, bool bIsStarting);
    
    UFUNCTION(BlueprintCallable)
    void OnNotifySkillTagUpdate(UASkill* Skill);
    
    UFUNCTION(BlueprintCallable)
    void OnNotifySkillStackUpdate(EAction TargetAction, int32 CurrentStack);
    
    UFUNCTION(BlueprintCallable)
    void OnNotifySkillPostUsed(UASkill* Skill);
    
    UFUNCTION(BlueprintCallable)
    void OnNotifySkillNoCost(EAction TargetAction);
    
    UFUNCTION(BlueprintCallable)
    void OnNotifySkillCancel(EAction TargetAction);
    
    UFUNCTION(BlueprintCallable)
    void OnNotifySkillAvailable(EAction TargetAction);
    
    UFUNCTION(BlueprintCallable)
    void OnNotifySkillAnimNotify();
    
    UFUNCTION(BlueprintCallable)
    void OnEndLoadSkillAsset(EAction Action, TSoftClassPtr<UASkill> SoftClass);
    
    UFUNCTION(BlueprintCallable)
    void LoadSkillAssets(const TMap<EAction, TSoftClassPtr<UASkill>>& SkillAssets);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanPressedSkill(UASkill* Skill) const;
    
    UFUNCTION(BlueprintCallable)
    void AddSkillInput(FSkillInputBP SkillInput);
    
    UFUNCTION(BlueprintCallable)
    void AddSkill(TSubclassOf<UASkill> NewSkill);
    
};

