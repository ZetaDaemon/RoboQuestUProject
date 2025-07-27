#pragma once
#include "CoreMinimal.h"
#include "GameStateDataAsset.h"
#include "OutGameStateDataAsset.generated.h"

class AActor;
class UDataTable;

UCLASS(Blueprintable)
class ROBOQUEST_API UOutGameStateDataAsset : public UGameStateDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* DT_MetaRewardBoard;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> BaseBasecampLayer;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> ShootingRangeLayer[2];
    
    UOutGameStateDataAsset();

};

