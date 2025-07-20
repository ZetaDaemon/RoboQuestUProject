#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Interface -FallbackName=Interface
#include "ISpawnable.generated.h"

class AACharacter;
class AActor;

UINTERFACE(Blueprintable, MinimalAPI)
class UISpawnable : public UInterface {
    GENERATED_BODY()
};

class IISpawnable : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetNewSpawnOwner(AACharacter* NewOwner);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnUnspawned();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnSpawned(float InDuration, bool bPlaySpawnEffect);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void InitializeSpawnable(AACharacter* InSpawnOwner);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    AActor* GetSpawnOwner();
    
};

