#pragma once
#include "CoreMinimal.h"
#include "Request_Game_PerkUpgrade.generated.h"

USTRUCT(BlueprintType)
struct FRequest_Game_PerkUpgrade {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString PerkName;
    
    ROBOQUEST_API FRequest_Game_PerkUpgrade();
};

