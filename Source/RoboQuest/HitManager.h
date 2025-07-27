#pragma once
#include "CoreMinimal.h"
#include "DamageHitResult.h"
#include "SkillHitResult.h"
#include "HitManager.generated.h"

USTRUCT(BlueprintType)
struct FHitManager {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDamageHitResult> DamageHitResults;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSkillHitResult> HitResults;
    
    ROBOQUEST_API FHitManager();
};

