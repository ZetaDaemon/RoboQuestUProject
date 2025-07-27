#pragma once
#include "CoreMinimal.h"
#include "LevelRowHandle.h"
#include "MaxTextRowHandle.h"
#include "FirstTimeMaxText.generated.h"

USTRUCT(BlueprintType)
struct FFirstTimeMaxText {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLevelRowHandle Level;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaxTextRowHandle TextByLocation[3];
    
    ROBOQUEST_API FFirstTimeMaxText();
};

