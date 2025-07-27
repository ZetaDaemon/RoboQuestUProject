#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=IntPoint -FallbackName=IntPoint
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=PrimaryDataAsset -FallbackName=PrimaryDataAsset
#include "AffixEliteLuck.h"
#include "AffixLuck.h"
#include "WeaponAffixRarities.h"
#include "WeaponAffixRowHandle.h"
#include "WeaponDataAsset.generated.h"

class UAnimMontage;
class UCurveFloat;
class UDataTable;
class USoundCue;

UCLASS(Blueprintable)
class ROBOQUEST_API UWeaponDataAsset : public UPrimaryDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* DT_WeaponAffix;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAffixLuck> BaseWeaponAffixLuck;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAffixLuck> StarterWeaponAffixLuck;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAffixLuck> MaxWeaponAffixLuck;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAffixLuck> MerchantWeaponAffixLuck;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAffixLuck> SpecialWeaponAffixLuck;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<float> UpgradeWeaponLuck;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<float> MaxUpgradeWeaponLuck;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<float> SpecialUpgradeWeaponLuck;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FIntPoint> AffixRangeByWeaponLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWeaponAffixRarities> AffixBundleByLevel;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint AffixLevelForWeaponQuality[5];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAffixEliteLuck> AffixEliteLuckByLevel;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeaponAffixRowHandle DebugMissingAffixRowHandle[3];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* CoolingHighAnimationFPV[5];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* CoolingLowAnimationFPV[5];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* CoolingHighAnimationTPV[5];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* CoolingSpeedRatioByAmmo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CoolingLowTriggerPercent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* DT_WeaponMod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EnergizedReloadSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EnergizedFirerate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EnergizedDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* OverheatCommonSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* OverheatCommonHapticSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* OverheatCommonLoopSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D OverheatCommonLoopSoundFadeDelay;
    
    UWeaponDataAsset();

};

