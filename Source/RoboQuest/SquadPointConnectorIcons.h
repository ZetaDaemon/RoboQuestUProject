#pragma once
#include "CoreMinimal.h"
#include "SquadPointConnectorIcons.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct FSquadPointConnectorIcons {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* SelfIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* CenterIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* IndieIcon;
    
    ROBOQUEST_API FSquadPointConnectorIcons();
};

