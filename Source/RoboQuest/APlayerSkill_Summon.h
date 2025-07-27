#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ECollisionChannel -FallbackName=ECollisionChannel
#include "APlayerSkill.h"
#include "DelegateOnActivateSummonRefDelegate.h"
#include "DelegateOnUpdateMaxSummonRefDelegate.h"
#include "DelegateOnUpdateSummonRefDurationDelegate.h"
#include "EOutRangeBehavior.h"
#include "ESummonBehavior.h"
#include "NetworkSkillInfo.h"
#include "RQDamageInfo.h"
#include "Templates/SubclassOf.h"
#include "APlayerSkill_Summon.generated.h"

class AActor;
class ASummonStaticMesh;
class UAudioComponent;
class UParticleSystem;
class USoundCue;
class UStaticMesh;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROBOQUEST_API UAPlayerSkill_Summon : public UAPlayerSkill {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnActivateSummonRef DelegateOnActivateSummonRef;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnUpdateSummonRefDuration DelegateOnUpdateSummonRefDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESummonBehavior SummonBehavior;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRepSummonRefs, meta=(AllowPrivateAccess=true))
    TArray<AActor*> SummonRefs;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> SummonClass;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFollowCameraRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SummonLifespan;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SummonLifespanModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 MaxSummonALive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ECollisionChannel> CollisionChannel;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnUpdateMaxSummonRef DelegateOnUpdateMaxSummonRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 MaxSummonSpawned;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EOutRangeBehavior OutRangeBehavior;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpawnRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpawnScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinWallDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* SpawnFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* SpawnSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector SummonSpawnLocationOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bGroundOffset;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<int32, float> ActivateSummonRefs;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASummonStaticMesh* HoloMeshRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* HoloMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform HoloTransformOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* HoloStartSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* HoloLoopSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* HoloStopSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D HoloSoundFadeDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAudioComponent* PlayedHoloLoopSound;
    
public:
    UAPlayerSkill_Summon(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
    UFUNCTION(BlueprintCallable)
    void SpawnHoloMesh();
    
private:
    UFUNCTION(BlueprintCallable)
    void ProcessSpawn(FNetworkSkillInfo NetworkInfo);
    
protected:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerRepositionate(FTransform NewTransfrom);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnRepSummonRefs();
    
protected:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastRepositionate(FTransform NewTransfrom);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnLevelGenerationChanged(bool bIsGenerating);
    
    UFUNCTION(BlueprintCallable)
    void OnDoorCrossedByAllPlayers(const FVector& DoorLocation, const FVector& ForwardVector);
    
    UFUNCTION(BlueprintCallable)
    void OnActivateAIDeath(const FRQDamageInfo& DamageInfo);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FVector GetTeleportLocation();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetSummonRefActivateAmount() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FVector GetSummonLocation(FVector StartTrace, FVector ForwardVector, bool& bTriggerGroundOffset);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    float GetSummonLifespawn() const;
    
    UFUNCTION(BlueprintCallable)
    FTransform GetSpawnTransform(const FVector& StartTrace, const FVector& ForwardVector, bool bIsHolo);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    float GetSpawnRange() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FVector GetSpawnLocation(FVector StartTrace, FVector ForwardVector, bool& bTriggerGroundOffset);
    
    UFUNCTION(BlueprintCallable)
    AActor* GetLongerActivateSummonRef();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FTransform GetHoloSpawnTransform(const FTransform& BaseSpawnTransform, const FVector& ForwardVector) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FVector GetHoloLocation(FVector StartTrace, FVector ForwardVector, bool& bTriggerGroundOffset);
    
public:
    UFUNCTION(BlueprintCallable)
    void DeactivateAllSummonRefs();
    
protected:
    UFUNCTION(BlueprintCallable)
    void AddMaxSummonRef(int32 AddAmount);
    
};

