#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Interface -FallbackName=Interface
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "ILootable.generated.h"

class AActor;

UINTERFACE(Blueprintable, MinimalAPI)
class UILootable : public UInterface {
    GENERATED_BODY()
};

class IILootable : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnLooted(const FVector& LootLocation, AActor* LootOwner);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void InitializeLootable();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    TArray<AActor*> GetLoot() const;
    
};

