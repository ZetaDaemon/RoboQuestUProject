#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Interface -FallbackName=Interface
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=HitResult -FallbackName=HitResult
#include "IGrappable.generated.h"

class ACharacter_Player;

UINTERFACE(Blueprintable, MinimalAPI)
class UIGrappable : public UInterface {
    GENERATED_BODY()
};

class IIGrappable : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool ShouldAttractActor() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnStartGrapped(ACharacter_Player* Grapper);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnEndGrapped(ACharacter_Player* Grapper);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool LaunchWithVelocity() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool GetGrabPoint(const FHitResult& HitResult, FVector& GrabPoint) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FVector GetBaseLocation() const;
    
};

