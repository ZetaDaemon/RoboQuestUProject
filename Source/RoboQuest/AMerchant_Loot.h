#pragma once
#include "CoreMinimal.h"
#include "AMerchant.h"
#include "EMultiplayerLoot.h"
#include "IReplicatedActor.h"
#include "ITileReplicatedActor.h"
#include "AMerchant_Loot.generated.h"

class AATile;
class AActor;
class USceneComponent;

UCLASS(Blueprintable)
class ROBOQUEST_API AAMerchant_Loot : public AAMerchant, public IIReplicatedActor, public IITileReplicatedActor {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateOnAllLootRegistered);
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRepReplicatedLoot, meta=(AllowPrivateAccess=true))
    TArray<AActor*> ReplicatedLoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> RegisteredLoot;
    
public:
    AAMerchant_Loot(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
    UFUNCTION(BlueprintCallable)
    void UnregisterLoot(AActor* Loot);
    
    UFUNCTION(BlueprintCallable)
    void RegisterLoot(AActor* Loot);
    
    UFUNCTION(BlueprintCallable)
    void OnRepReplicatedLoot();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintLootUnregistered(AActor* Loot);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintLootRegistered(AActor* Loot);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    TArray<AActor*> GetLoots(EMultiplayerLoot MultiplayerLoot);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    uint8 GetLootAmount(EMultiplayerLoot MultiplayerLoot);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    uint8 GetAllLootAmount();
    

    // Fix for true pure virtual functions not being implemented
public:
    UFUNCTION(BlueprintCallable)
    AATile* GetSlotParentTile() const override PURE_VIRTUAL(GetSlotParentTile, return NULL;);
    
    UFUNCTION(BlueprintCallable)
    AActor* GetSlotParentActor() const override PURE_VIRTUAL(GetSlotParentActor, return NULL;);
    
    UFUNCTION(BlueprintCallable)
    USceneComponent* GetSlotComponent() const override PURE_VIRTUAL(GetSlotComponent, return NULL;);
    
};

