#pragma once
#include "CoreMinimal.h"
#include "RankIcon.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct FRankIcon {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* Icon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* SmallIcon;
    
    ROBOQUEST_API FRankIcon();
};

