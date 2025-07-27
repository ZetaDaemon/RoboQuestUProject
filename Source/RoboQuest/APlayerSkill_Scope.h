#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
#include "APlayerSkill.h"
#include "Animation.h"
#include "APlayerSkill_Scope.generated.h"

class UASkill;
class UAudioComponent;
class UModifier_Stat;
class USoundCue;
class UTexture2D;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROBOQUEST_API UAPlayerSkill_Scope : public UAPlayerSkill {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsScopped;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* ScopeChargedStartSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* ScopeChargedLoopSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D ScopeChargedLoopFadeDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* ScopeChargedMaxReachedSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D ScopeChargedPitchAmplitude;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UModifier_Stat* ChargedDamageModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAudioComponent* ChargedScopeLoopingSoundComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bChargedScope;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* ScopeHUD;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimation InAnimation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimation OutAnimation;
    
public:
    UAPlayerSkill_Scope(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetNewChargedDuration(float InDuration);
    
    UFUNCTION(BlueprintCallable)
    void RemoveChargedScope();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnWeaponUsedSkill(UASkill* Skill, bool bIsStarting);
    
public:
    UFUNCTION(BlueprintCallable)
    void InitializeChargedScope();
    
private:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetPostShootScopeDelay();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FAnimation GetOutAnimation();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FAnimation GetInAnimation();
    
};

