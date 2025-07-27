#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=LinearColor -FallbackName=LinearColor
#include "AProjectile.h"
#include "IDamageable.h"
#include "AAIProjectile.generated.h"

class AACharacter;
class AActor;
class ACharacter_AI;
class USceneComponent;
class USphereComponent;

UCLASS(Blueprintable)
class ROBOQUEST_API AAAIProjectile : public AAProjectile, public IIDamageable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ACharacter_AI* AIOwner;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* CollisionDamageComponent;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USceneComponent* HomingComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* HomingTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AACharacter* TargetHomingCharacter;
    
public:
    AAAIProjectile(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnTargetHomingCharacterTargetable(bool bTargetable, AActor* NewTarget);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FLinearColor GetFXProjectileColor() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FLinearColor GetBaseProjectileColor() const;
    

    // Fix for true pure virtual functions not being implemented
};

