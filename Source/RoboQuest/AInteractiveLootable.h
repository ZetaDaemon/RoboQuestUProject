#pragma once
#include "CoreMinimal.h"
#include "AInteractiveWidget.h"
#include "EMultiplayerLoot.h"
#include "ILootable.h"
#include "AInteractiveLootable.generated.h"

class AActor;
class UStaticMeshComponent;

UCLASS(Abstract, Blueprintable)
class ROBOQUEST_API AAInteractiveLootable : public AAInteractiveWidget, public IILootable {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnDestroy, AActor*, Loot);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* PhysicMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    EMultiplayerLoot MultiplayerLoot;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PhysicsImpulseHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RandomPhysicsLateralImpulse;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StopCalculatePhysicOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StartCalculateStopPhysicTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GravityIncreaseRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxGravity;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnDestroy DelegateOnDestroy;
    
    AAInteractiveLootable(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintStopPhysic();
    
public:
    UFUNCTION(BlueprintCallable)
    void NotifyOnDestroy();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsActiveLocally();
    

    // Fix for true pure virtual functions not being implemented
};

