#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
#include "ATile.h"
#include "EDoorState.h"
#include "EStat.h"
#include "EnemyRow.h"
#include "RQDamageInfo.h"
#include "Templates/SubclassOf.h"
#include "ABossTile.generated.h"

class AABossTile;
class AADoor;
class AAJumpad;
class AALavaTrap;
class AActor;
class ACharacter_Enemy;
class USkeletalMeshComponent;

UCLASS(Blueprintable)
class ROBOQUEST_API AABossTile : public AATile {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateDisplayBossHealthBar, AABossTile*, InBossTile, ACharacter_Enemy*, InBossRef);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateBossHealthChanged, float, currentValue, float, FullValue);
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* BossLayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<ACharacter_Enemy> BossClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FName BossRowName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FEnemyRow BossRow;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> TeleportPoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AAJumpad*> BossLayerJumpads;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AALavaTrap*> BossLayerLavaTraps;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<USkeletalMeshComponent*> SkeletalMeshComponents;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsBossCombatStarted;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<ACharacter_Enemy*> BossRefs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInstantFadeToBlackOnBossDeath;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateDisplayBossHealthBar DelegateDisplayBossHealthBar;
    
private:
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FTransform> MerchantsSpawnTransforms;
    
public:
    AABossTile(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void TeleportPlayersToBossCombat();
    
public:
    UFUNCTION(BlueprintCallable)
    void StartSequence();
    
protected:
    UFUNCTION(BlueprintCallable)
    void StartBossCombat();
    
private:
    UFUNCTION(BlueprintCallable)
    void ResurrectDeadPlayersOnBossDeath();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnSkeletalMeshOwnerDestroyed(AActor* Actor);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnSequenceFinished();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnSafeZoneDoorStateChanged(AADoor* Door, EDoorState NewState);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnBossStatChanged(EStat Stat, float currentValue, float Value);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnBossDoorOpened(AADoor* Door, EDoorState NewState);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnBossDeath(const FRQDamageInfo& DamageInfo);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintBossDefeatedFadeToBlack();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasABoss() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ACharacter_Enemy* GetFirstBossRef() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    float GetFadeToBlackDelayAfterBossDeath() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetBossRowName() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetBossName() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetBossLayer() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    uint8 GetBossEncounterID() const;
    
    UFUNCTION(BlueprintCallable)
    void DisplayBossHealthBar();
    
    UFUNCTION(BlueprintCallable)
    void DisablePlayersInputThenStartSequence(bool bStartSequence);
    
private:
    UFUNCTION(BlueprintCallable)
    void DelayedFadeToBlack();
    
    UFUNCTION(BlueprintCallable)
    void DelayedBossAIActivation();
    
public:
    UFUNCTION(BlueprintCallable)
    void BindEventsAndDeactivateBoss(ACharacter_Enemy* Boss);
    
};

