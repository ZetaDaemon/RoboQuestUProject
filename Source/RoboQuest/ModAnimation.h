#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TableRowBase -FallbackName=TableRowBase
#include "Engine/DataTable.h"
#include "ModAnimationGunfeel.h"
#include "ModProjectileMesh.h"
#include "ModAnimation.generated.h"

class AAWeapon;
class UAnimMontage;

USTRUCT(BlueprintType)
struct FModAnimation : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FModAnimationGunfeel PlayerAnimationsFPV[5];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* PlayerAnimationsTPV[5];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TSoftClassPtr<AAWeapon>, FModAnimationGunfeel> SpecificPlayerAnimationFPV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TSoftClassPtr<AAWeapon>, UAnimMontage*> SpecificPlayerAnimationTPV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPlayWeaponAnimation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TSoftClassPtr<AAWeapon>, UAnimMontage*> SpecificWeaponAnimation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TSoftClassPtr<AAWeapon>, FModProjectileMesh> SpecificProjectileMesh;
    
    ROBOQUEST_API FModAnimation();
};

