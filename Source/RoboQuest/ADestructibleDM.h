#pragma once
#include "CoreMinimal.h"
#include "ADestructible.h"
#include "ADestructibleDM.generated.h"

class UPrimitiveComponent;

UCLASS(Abstract, Blueprintable)
class ROBOQUEST_API AADestructibleDM : public AADestructible {
    GENERATED_BODY()
public:
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LifeSpan;
    
public:
    AADestructibleDM(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnDestroy();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnComponentCollisionSettingsChangedEvent(UPrimitiveComponent* ChangedComponent);
    
};

