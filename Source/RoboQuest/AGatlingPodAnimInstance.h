#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Rotator -FallbackName=Rotator
#include "APodAnimInstance.h"
#include "AGatlingPodAnimInstance.generated.h"

class UASkill;

UCLASS(Blueprintable, NonTransient)
class UAGatlingPodAnimInstance : public UAPodAnimInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsAttacking;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PreshootRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AnimBarrelRotationZ;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FRotator AnimBarrelRotation;
    
    UAGatlingPodAnimInstance();

private:
    UFUNCTION(BlueprintCallable)
    void OnUpdatePreshootRatio(float NewPreshootRatio);
    
    UFUNCTION(BlueprintCallable)
    void OnNotifySkillUsed(UASkill* Skill, bool bIsUsed);
    
    UFUNCTION(BlueprintCallable)
    void OnEndInitialization();
    
};

