#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include "AShootingRangeLight.generated.h"

class AAGameState;
class USceneComponent;
class UStaticMeshComponent;

UCLASS(Abstract, Blueprintable)
class ROBOQUEST_API AAShootingRangeLight : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* Mesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Index;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ActivationDelay;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AAGameState* GameStateRef;
    
public:
    AAShootingRangeLight(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnEndTimerActivation();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AAGameState* GetGameStateRef();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void DeactivateLight();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ActivateLight();
    
};

