#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TableRowBase -FallbackName=TableRowBase
#include "Engine/DataTable.h"
#include "PlayerRow.h"
#include "RQPlayer.generated.h"

USTRUCT(BlueprintType)
struct FRQPlayer : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerRow Player;
    
    ROBOQUEST_API FRQPlayer();
};

