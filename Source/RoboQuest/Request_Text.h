#pragma once
#include "CoreMinimal.h"
#include "Request_Text.generated.h"

USTRUCT(BlueprintType)
struct FRequest_Text {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString RowName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Tri;
    
    ROBOQUEST_API FRequest_Text();
};

