#pragma once
#include "CoreMinimal.h"
#include "RoofClasses.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FRoofClasses {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<AActor>> Classes;
    
    ROBOQUEST_API FRoofClasses();
};

