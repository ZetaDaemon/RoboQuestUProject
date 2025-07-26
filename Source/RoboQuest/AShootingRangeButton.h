#pragma once
#include "CoreMinimal.h"
#include "AInteractive.h"
#include "AShootingRangeButton.generated.h"

class UStaticMeshComponent;

UCLASS(Abstract, Blueprintable)
class ROBOQUEST_API AAShootingRangeButton : public AAInteractive {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* ButtonMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bReplicateInteraction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Index;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Cooldown;
    
public:
    AAShootingRangeButton(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PlayInteractFeedback();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnEndCooldown();
    
};

