#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=IntPoint -FallbackName=IntPoint
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include "AIColorRowHandle.h"
#include "EEnemyType.h"
#include "EStat.h"
#include "EStatus.h"
#include "EnemyDeathRowHandle.h"
#include "IDamageable.h"
#include "IStatManager.h"
#include "RQDamageInfo.h"
#include "SFXSurface.h"
#include "StatValues.h"
#include "StatusSound.h"
#include "SurfaceSoundAndFx.h"
#include "ATarget.generated.h"

class AACharacter;
class AAGameState;
class AATarget;
class UAStatManager;
class UAnimMontage;
class UArrowComponent;
class UAudioComponent;
class UCapsuleComponent;
class UCurveFloat;
class UMaterialInstanceDynamic;
class UParticleSystemComponent;
class USceneComponent;
class USkeletalMeshComponent;

UCLASS(Abstract, Blueprintable)
class ROBOQUEST_API AATarget : public AActor, public IIDamageable, public IIStatManager {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateTargetUpdateHitBlend, float, NewHitBlend);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateTargetUpdateHeight, float, NewHeight);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateTargetTakeDamage, AACharacter*, DamageInstigator, float, DamageTake);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateTargetDead, AATarget*, Target, bool, bIsDead);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDelegateOnDispatchTargetStatus, EStatus, Status, bool, bIsStart, float, Duration);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCapsuleComponent* CapsuleComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* TargetMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* HomingComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UArrowComponent* ArrowLeft;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UArrowComponent* ArrowRight;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanMove;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Health;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ImpactResistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StaggerDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CapsuleHalfHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CapsuleRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DeathDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 KillAmountToRespawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RespawnKillDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> CriticalBones;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemyType Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Score;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRevertMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFlipMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Height;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Index;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DelayBeforeRaise;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DelayBeforeResetToInitialPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UpAndDownSpeed;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint Translation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Speed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStartRight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DelayBeforeUpAndDown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStartUp;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 HealthBarSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StatusRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAIColorRowHandle ColorRow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnemyDeathRowHandle DeathRow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAnimMontage*> HitAnimations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAnimMontage*> CriticalHitAnimations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* StaggerAnimation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* StunAnimation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HitBlendMultiplier;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AAGameState* GameStateRef;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSFXSurface DeathSFX[10];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSurfaceSoundAndFx DeathSoundsAndFXs;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateTargetDead DelegateTargetDead;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateTargetTakeDamage DelegateTargetTakeDamage;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRQDamageInfo LastDamageInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInstanceDynamic*> DynamicMaterials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<EStatus, AActor*> StatusInstigators;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FStatusSound StatusSound[19];
    
    UPROPERTY(EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAudioComponent* StatusAudioComponent[19];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCurveFloat* CurveImpactRegeneration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCurveFloat* CurveStunRegeneration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCurveFloat* CurveIceRegeneration;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 InitialParticleSystemPoolCount;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UParticleSystemComponent*> ParticleSystemComponentsPool;
    
public:
    AATarget(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void StartUpAndDown();
    
    UFUNCTION(BlueprintCallable)
    void StartMoving();
    
    UFUNCTION(BlueprintCallable)
    void SetTargetActivate(bool bNewActivate);
    
public:
    UFUNCTION(BlueprintCallable)
    void RemoveAllStatus();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnEndResetToInitialPositionTimer();
    
    UFUNCTION(BlueprintCallable)
    void OnDelegateTargetDeath(int32 TargetIndex, AATarget* TargetRef);
    
    UFUNCTION(BlueprintCallable)
    void OnDeathDurationEnd();
    
    UFUNCTION(BlueprintCallable)
    void OnCommonEnemyDataAssetLoaded();
    
protected:
    UFUNCTION(BlueprintCallable)
    void InitializeMesh();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AAGameState* GetGameStateRef();
    
public:
    

    // Fix for true pure virtual functions not being implemented
    UFUNCTION(BlueprintCallable)
    bool RestoreStat(EStat enumStat, float Modifier) override PURE_VIRTUAL(RestoreStat, return false;);
    
    UFUNCTION(BlueprintCallable)
    bool ReduceStat(EStat enumStat, float Modifier) override PURE_VIRTUAL(ReduceStat, return false;);
    
    UFUNCTION()
    void OnNotifyStatFull(EStat enumStat) override PURE_VIRTUAL(OnNotifyStatFull,);
    
    UFUNCTION()
    void OnNotifyStatEmpty(EStat enumStat) override PURE_VIRTUAL(OnNotifyStatEmpty,);
    
    UFUNCTION()
    void OnNotifyStat(EStat enumStat, float curVal, float Value) override PURE_VIRTUAL(OnNotifyStat,);
    
    UFUNCTION(BlueprintCallable)
    void MinimiseStat(EStat enumStat) override PURE_VIRTUAL(MinimiseStat,);
    
    UFUNCTION(BlueprintCallable)
    void MaximiseStat(EStat enumStat) override PURE_VIRTUAL(MaximiseStat,);
    
    UFUNCTION(BlueprintCallable)
    bool HaveStat(EStat enumStat) const override PURE_VIRTUAL(HaveStat, return false;);
    
    UFUNCTION(BlueprintCallable)
    float GetStatValue(EStat enumStat) const override PURE_VIRTUAL(GetStatValue, return 0.0f;);
    
    UFUNCTION(BlueprintCallable)
    FStatValues GetStatStruct(EStat enumStat) const override PURE_VIRTUAL(GetStatStruct, return FStatValues{};);
    
    UFUNCTION(BlueprintCallable)
    UAStatManager* GetStatManager() const override PURE_VIRTUAL(GetStatManager, return NULL;);
    
    UFUNCTION(BlueprintCallable)
    float GetStatCurrentValue(EStat enumStat) const override PURE_VIRTUAL(GetStatCurrentValue, return 0.0f;);
    
    UFUNCTION(BlueprintCallable)
    float GetMoveStatValue(float InitialValue) const override PURE_VIRTUAL(GetMoveStatValue, return 0.0f;);
    
};

