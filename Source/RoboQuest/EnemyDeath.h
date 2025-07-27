#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TableRowBase -FallbackName=TableRowBase
#include "Engine/DataTable.h"
#include "SFXSurface.h"
#include "EnemyDeath.generated.h"

USTRUCT(BlueprintType)
struct FEnemyDeath : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FSFXSurface SFX[10];
    
    ROBOQUEST_API FEnemyDeath();
};

