#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=PrimaryDataAsset -FallbackName=PrimaryDataAsset
#include "EElement.h"
#include "SkillDataAsset.generated.h"

class UCurveFloat;
class UDataTable;
class UParticleSystem;

UCLASS(Blueprintable)
class ROBOQUEST_API USkillDataAsset : public UPrimaryDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* DT_PlayerSkills;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* DT_EnemySkill;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* DT_AllySkill;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* DT_ModSkills;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExplosionFXQueueDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultExplosionFXQueueRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* ExplosionFXQueueCurve;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* ExplosionByElement[3];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* TrailByElement[3];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* ProjectileParticleByElement[3];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* ProjectileTrailByElement[3];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* BashByElement[3];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EElement> MuzzleElementOrder;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EElement> TrailElementOrder;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EElement> HitElementOrder;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EElement> ProjectileElementOrder;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EElement> ProjectileElementTrailOrder;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EElement> ExplosionElementOrder;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* CurveFallOffDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* CurveFallOffImpactForce;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* CurveAreaBoneFallOff;
    
    USkillDataAsset();

};

