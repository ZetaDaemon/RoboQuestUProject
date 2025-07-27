#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Interface -FallbackName=Interface
#include "ISpecialElement.generated.h"

UINTERFACE(Blueprintable, MinimalAPI)
class UISpecialElement : public UInterface {
    GENERATED_BODY()
};

class IISpecialElement : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTileValidated();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPlayerExit();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPlayerEnter(float SyncDelayInSeconds);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDoorOpened();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnAllEnemiesOfWaveAreDead(int32 WaveID);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Initialize();
    
};

