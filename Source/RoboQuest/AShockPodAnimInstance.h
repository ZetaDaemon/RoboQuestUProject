#pragma once
#include "CoreMinimal.h"
#include "APodAnimInstance.h"
#include "AShockPodAnimInstance.generated.h"

class UASkill;

UCLASS(Blueprintable, NonTransient)
class ROBOQUEST_API UAShockPodAnimInstance : public UAPodAnimInstance {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDeployed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOpeningToOpen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOpenToClosing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bClosingToClose;
    
public:
    UAShockPodAnimInstance();

private:
    UFUNCTION(BlueprintCallable)
    void OnUsePrimaryFireSkill(UASkill* Skill, bool bIsStarting);
    
    UFUNCTION(BlueprintCallable)
    void OnPrimaryFireSkillAreaDelay();
    
    UFUNCTION(BlueprintCallable)
    void OnEndInitialization();
    
};

