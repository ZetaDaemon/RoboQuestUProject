#pragma once
#include "CoreMinimal.h"
#include "CompendiumDataCategory.generated.h"

class ACharacter_Player;

USTRUCT(BlueprintType)
struct FCompendiumDataCategory {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Version;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACharacter_Player* PlayerRef;
    
    ROBOQUEST_API FCompendiumDataCategory();
};

