#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "EGameplayTags.h"
#include "EItemType.h"
#include "Item.h"
#include "AItem.generated.h"

class ACharacter_Player;
class UAItem;
class UAPlayerSkill;
class UASkill;
class UModifier_Stat;
class UParticleSystem;

UCLASS(Blueprintable)
class ROBOQUEST_API UAItem : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ItemRowName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAItem* BaseItemRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RandomSeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACharacter_Player* PlayerRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItem ItemData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EItemType ItemType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EGameplayTags, UParticleSystem*> TrailByElement;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SparkFirerate;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAPlayerSkill* ClassSkillRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAPlayerSkill* BashSkillRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UModifier_Stat* WeaponSlotModifier;
    
public:
    UAItem();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStartReplicatedEffect();
    
    UFUNCTION(BlueprintCallable)
    void OnRemoveWeaponSlot();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnApply(bool bFromRunSave);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool IsPassive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLocallyControlled() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsElementalDamage(int32 GameplayTags) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetSparkFirerate() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetSparkAmount(UASkill* InSkill) const;
    
    UFUNCTION(BlueprintCallable)
    bool GetSeededRandomResult(int32 Luck, int32 LuckIncrementByFail, float FireRate);
    
private:
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UParticleSystem* GetElementalTrail(int32 GameplayTags) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCustomFloatValue(FName PropertyName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAPlayerSkill* GetClassSkill() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAPlayerSkill* GetBashSkill() const;
    
    UFUNCTION(BlueprintCallable)
    bool GetBaseSeededRandomResult();
    
};

