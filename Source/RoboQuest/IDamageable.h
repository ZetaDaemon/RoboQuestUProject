#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Interface -FallbackName=Interface
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=HitResult -FallbackName=HitResult
#include "EBonesType.h"
#include "EBumpIntensity.h"
#include "EStatus.h"
#include "ETeam.h"
#include "ETrapType.h"
#include "RQDamageInfo.h"
#include "IDamageable.generated.h"

class AACharacter;
class AActor;
class ACharacter_AI;
class UMaterialInstanceDynamic;
class UPrimitiveComponent;
class USceneComponent;

UINTERFACE(Blueprintable)
class UIDamageable : public UInterface {
    GENERATED_BODY()
};

class IIDamageable : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void UnregisterToTokenSystem(ACharacter_AI* InEnemy);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool ShouldConsumeHit();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool ShouldBlockHit(UPrimitiveComponent* HitComponent);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void RegisterToTokenSystem(ACharacter_AI* InEnemy, bool bHighPriority);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnTriggerRocketJump(const FVector& ForwardVector, const FVector& TriggerLocation, float Radius);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnTriggerDeath(const FRQDamageInfo& DamageInfo);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnRemoveStatus(EStatus Status);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnDealDamage(const FRQDamageInfo& DamageInfo);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnBumped(const FVector& ForwardVector, EBumpIntensity Intensity);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnApplyStatus(EStatus Status, float Duration, AActor* Instigator);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnApplyDamage(float DamageAmount, float ImpactForceAmount, AACharacter* DamageInstigator, int32 GameplayTags, float IceRatio, float ShockRatio);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnApplyCosmeticDamage(FRQDamageInfo DamageInfo);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsDead();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsAllyTeam(ETeam Team);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool HaveTokenSystem();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool HaveStatus(EStatus Status);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    float GetTrapDamageModifier(ETrapType Type);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    ETeam GetTeam();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    float GetTargetThreat();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FVector GetTargetNavLocation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FVector GetTargetLocation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    float GetStatusStayDuration(EStatus Status);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    TArray<EStatus> GetStatus();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FVector GetRicochetLocation();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FName GetPierceTag();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    USceneComponent* GetHomingComponent();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FVector GetGamepadMagnetismLocation(const FVector& StartTrace, const FVector& ForwardVector) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FVector GetFalloffCalculateLocation(const FHitResult& HitResult);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    TArray<UMaterialInstanceDynamic*> GetDynamicMaterials();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    float GetDamageModifierRatio();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    TArray<FVector> GetDamageLocation();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    UPrimitiveComponent* GetDamageablePrimitiveComponent();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    float GetCriticalBoneRatio(const FHitResult& HitResult);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    EBonesType GetBoneType(const FHitResult& HitResult);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool CanTakeDamage();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool CanDie();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool CanBeHommed();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void AddStatusDuration(EStatus Status, float AddDuration);
    
};

