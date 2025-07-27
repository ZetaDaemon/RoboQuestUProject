#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "AInteractiveLootable.h"
#include "EAnimPose.h"
#include "EElement.h"
#include "EWeaponMetaRewardModifier.h"
#include "Keyword.h"
#include "Templates/SubclassOf.h"
#include "AInteractiveWeapon.generated.h"

class AAInteractiveWeapon;
class AAWeapon;
class UMaterialInstanceDynamic;
class UParticleSystem;
class UParticleSystemComponent;
class USceneComponent;
class USkeletalMeshComponent;
class USoundCue;

UCLASS(Abstract, Blueprintable)
class ROBOQUEST_API AAInteractiveWeapon : public AAInteractiveLootable {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnWeaponSpawned, AAInteractiveWeapon*, InteractiveWeapon);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Scene;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* WeaponMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UParticleSystemComponent* WeaponBeam;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UParticleSystemComponent* WeaponStar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UParticleSystemComponent* WeaponMod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=RepNotify_SpawnedWeapon, meta=(AllowPrivateAccess=true))
    AAWeapon* SpawnedWeapon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AAWeapon> WeaponClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AAWeapon> WeaponClassSoftPtr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UParticleSystem> WeaponStarFXSoftPtr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UParticleSystem> WeaponModFXSoftPtr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 WeaponLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BaseRandomSeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 AffixAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWeaponMetaRewardModifier MetaRewardModifier;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform MeshTransformByType[5];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector WeaponModLocationOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USoundCue> LootedSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDebugOffset;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnWeaponSpawned DelegateOnWeaponSpawned;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInitialized;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UParticleSystem* WeaponStarFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UParticleSystem* WeaponModFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* WeaponStarDynamicMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* WeaponModDynamicMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* LootedSoundLoaded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FKeyword> WeaponNameKeywordArray;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAlreadyInteracted;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText PendingWeaponText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText PurchaseText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText EquipText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText SuperbotInteractText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText SwitchText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<float> UROVisibleDistanceFactorThesholds;
    
    AAInteractiveWeapon(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
    UFUNCTION(BlueprintCallable)
    void UpdateWeaponStarIcon();
    
    UFUNCTION(BlueprintCallable)
    void UpdateWeaponModIcon();
    
    UFUNCTION(BlueprintCallable)
    void UpdateBeamColor();
    
    UFUNCTION(BlueprintCallable)
    void SetWeaponElement(EElement Element);
    
public:
    UFUNCTION(BlueprintCallable)
    void SetScreenshotMode(bool bScreenshotMode);
    
private:
    UFUNCTION(BlueprintCallable)
    void RepNotify_SpawnedWeapon();
    
    UFUNCTION(BlueprintCallable)
    void OnWeaponUpdateAffix();
    
    UFUNCTION(BlueprintCallable)
    void OnWeaponSpawned();
    
    UFUNCTION(BlueprintCallable)
    void OnWeaponLevelUp(int32 NewLevel);
    
    UFUNCTION(BlueprintCallable)
    void OnWeaponInitialize(AAWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    void OnUpdateLocalization(const FString& NewLanguage);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnEndTimerDestroyBasecamp();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnBoneHidden(const FName& BoneName, bool bNewHidden);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintDebugOffset();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsExcludedForSuperbot(FText& ExcludeText) const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FTransform GetMeshTransformByType(EAnimPose animPose) const;
    
};

