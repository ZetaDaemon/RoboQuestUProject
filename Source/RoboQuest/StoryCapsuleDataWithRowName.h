#pragma once
#include "CoreMinimal.h"
#include "StoryCapsule.h"
#include "StoryCapsuleDataWithRowName.generated.h"

USTRUCT(BlueprintType)
struct FStoryCapsuleDataWithRowName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RowName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStoryCapsule StoryCapsuleRow;
    
    ROBOQUEST_API FStoryCapsuleDataWithRowName();
};

