#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=LinearColor -FallbackName=LinearColor
#include "ASlot.h"
#include "MaxAnimationRowHandle.h"
#include "AMaxSlot.generated.h"

class AActor;

UCLASS(Abstract, Blueprintable)
class ROBOQUEST_API AAMaxSlot : public AASlot {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaxAnimationRowHandle Anim;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> MaxClass;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor ColorByType[4];
    
    AAMaxSlot(const FObjectInitializer& ObjectInitializer);

};

