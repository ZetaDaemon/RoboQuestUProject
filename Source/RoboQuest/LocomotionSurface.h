#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TableRowBase -FallbackName=TableRowBase
#include "Engine/DataTable.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=PhysicsCore -ObjectName=EPhysicalSurface -FallbackName=EPhysicalSurface
#include "SFXSurface.h"
#include "LocomotionSurface.generated.h"

USTRUCT(BlueprintType)
struct FLocomotionSurface : public FTableRowBase {
    GENERATED_BODY()
public:
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseDefault;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FSFXSurface SFX[7];
    
    ROBOQUEST_API FLocomotionSurface();
};

