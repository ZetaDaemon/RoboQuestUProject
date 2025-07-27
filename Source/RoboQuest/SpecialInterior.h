#pragma once
#include "CoreMinimal.h"
#include "SpecialInterior.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FSpecialInterior {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<AActor>> Classes;
    
    ROBOQUEST_API FSpecialInterior();
};

