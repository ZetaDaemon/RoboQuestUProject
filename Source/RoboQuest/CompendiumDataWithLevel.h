#pragma once
#include "CoreMinimal.h"
#include "CompendiumData.h"
#include "CompendiumDataWithLevel.generated.h"

USTRUCT(BlueprintType)
struct FCompendiumDataWithLevel : public FCompendiumData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CompendiumLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CompletionAmount;
    
    ROBOQUEST_API FCompendiumDataWithLevel();
};

