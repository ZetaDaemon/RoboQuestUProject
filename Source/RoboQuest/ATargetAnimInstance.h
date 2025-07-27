#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=AnimInstance -FallbackName=AnimInstance
#include "EStatus.h"
#include "ATargetAnimInstance.generated.h"

class AATarget;

UCLASS(Abstract, Blueprintable, NonTransient)
class UATargetAnimInstance : public UAnimInstance {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AATarget* TargetRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsDead;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HitBlend;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsStunned;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFirstState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFlipMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Height;
    
public:
    UATargetAnimInstance();

private:
    UFUNCTION(BlueprintCallable)
    void OnTargetUpdateHitBlend(float NewHitBlend);
    
    UFUNCTION(BlueprintCallable)
    void OnTargetUpdateHeight(float NewHeight);
    
    UFUNCTION(BlueprintCallable)
    void OnTargetDispatchStatus(EStatus Status, bool bIsStart, float Duration);
    
    UFUNCTION(BlueprintCallable)
    void OnTargetDeath(AATarget* Target, bool bNewDead);
    
};

