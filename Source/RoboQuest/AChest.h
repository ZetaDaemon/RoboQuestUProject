#pragma once
#include "CoreMinimal.h"
#include "AInteractive.h"
#include "EMultiplayerLoot.h"
#include "IOrderableActor.h"
#include "AChest.generated.h"

class AAInteractiveLootable;
class AActor;

UCLASS(Abstract, Blueprintable)
class ROBOQUEST_API AAChest : public AAInteractive, public IIOrderableActor {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateOnFinishLootAllActors);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateOnAllLootRegistered);
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> PendingLoots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AAInteractiveLootable*> InteractiveLootables;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRepReplicatedLoot, meta=(AllowPrivateAccess=true))
    TArray<AActor*> ReplicatedLoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> RegisteredLoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLootFromQueue;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<float> UROVisibleDistanceFactorThesholds;
    
    AAChest(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
    UFUNCTION(BlueprintCallable)
    void UnregisterLoot(AActor* Loot);
    
    UFUNCTION(BlueprintCallable)
    void RegisterLoot(AActor* Loot);
    
    UFUNCTION(BlueprintCallable)
    void OpenChest();
    
    UFUNCTION(BlueprintCallable)
    void OnRepReplicatedLoot();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintOpenChestFromSpecial();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintLootUnregistered(AActor* Loot);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintLootRegistered(AActor* Loot);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    TArray<AActor*> GetLoots(EMultiplayerLoot MultiplayerLoot);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    uint8 GetLootAmount(EMultiplayerLoot MultiplayerLoot);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<AActor*> GetLocallyRegisteredLoots();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    uint8 GetAllLootAmount();
    
    UFUNCTION(BlueprintCallable)
    void FakeRegisterLoot();
    
private:
    UFUNCTION(BlueprintCallable)
    void DelayedActivateLootCollision();
    

    // Fix for true pure virtual functions not being implemented
};

