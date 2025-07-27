#pragma once
#include "CoreMinimal.h"
#include "GameStateDataAsset.h"
#include "Templates/SubclassOf.h"
#include "InGameStateDataAsset.generated.h"

class AAInteractiveItem;
class AAPickup;
class UCurveFloat;
class UDataTable;

UCLASS(Blueprintable)
class ROBOQUEST_API UInGameStateDataAsset : public UGameStateDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* DT_EnemyDeath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* DT_GameTips;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AAPickup> PickupClasses[11];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PickupPoolAmount[11];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MultiplayerTimePickupValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* CurveHealthPickup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisableWeaponPickupLoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 WeaponPickupLootValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MultiplayerWeaponPickupLootValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AAInteractiveItem> InteractiveItemClass;
    
    UInGameStateDataAsset();

};

