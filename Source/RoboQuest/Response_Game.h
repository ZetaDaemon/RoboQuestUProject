#pragma once
#include "CoreMinimal.h"
#include "Response_Game.generated.h"

USTRUCT(BlueprintType)
struct FResponse_Game {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ID;
    
    ROBOQUEST_API FResponse_Game();
};

