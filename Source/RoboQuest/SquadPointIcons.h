#pragma once
#include "CoreMinimal.h"
#include "SquadPointConnectorIcons.h"
#include "SquadPointIcons.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct FSquadPointIcons {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FSquadPointConnectorIcons ConnectorIcons[4];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* CenterIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* NotAttachedIcon;
    
    ROBOQUEST_API FSquadPointIcons();
};

