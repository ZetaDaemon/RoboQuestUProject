#pragma once
#include "CoreMinimal.h"
#include "LootRowHandle.h"
#include "LootBundle.generated.h"

USTRUCT(BlueprintType)
struct FLootBundle {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLootRowHandle> Solo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLootRowHandle> Multi;
    
    ROBOQUEST_API FLootBundle();
};

