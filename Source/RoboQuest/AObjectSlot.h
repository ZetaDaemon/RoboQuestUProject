#pragma once
#include "CoreMinimal.h"
#include "ASlot.h"
#include "LootRowHandle.h"
#include "AObjectSlot.generated.h"

UCLASS(Abstract, Blueprintable)
class ROBOQUEST_API AAObjectSlot : public AASlot {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLootRowHandle LootRow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 Priority;
    
    AAObjectSlot(const FObjectInitializer& ObjectInitializer);

};

