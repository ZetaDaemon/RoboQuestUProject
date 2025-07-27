#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "PostProcessClass.generated.h"

class AALightPostProcess;

USTRUCT(BlueprintType)
struct FPostProcessClass {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AALightPostProcess> PostProcessClassPtr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<AALightPostProcess> PostProcessClass;
    
    ROBOQUEST_API FPostProcessClass();
};

