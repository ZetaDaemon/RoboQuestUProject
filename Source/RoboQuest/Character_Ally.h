#pragma once
#include "CoreMinimal.h"
#include "Character_AI.h"
#include "EElement.h"
#include "RQDamageInfo.h"
#include "Character_Ally.generated.h"

class UModifier_Stat;
class UModifier_Stat_Scale_Level;
class UParticleSystem;
class USoundCue;

UCLASS(Blueprintable)
class ROBOQUEST_API ACharacter_Ally : public ACharacter_AI {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UModifier_Stat* DifficultyHealthModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UModifier_Stat_Scale_Level* ModHealth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UParticleSystem* DeathFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* DeathSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<EElement, float> Elements;
    
public:
    ACharacter_Ally(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void SetActivationDuringLevelGeneration(bool bIsGenerating);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void RemoveElemental(EElement Element);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnAllyKill(FRQDamageInfo DamageInfo);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void InitElemental(EElement Element, float ElementalRatio, bool bInit);
    
};

