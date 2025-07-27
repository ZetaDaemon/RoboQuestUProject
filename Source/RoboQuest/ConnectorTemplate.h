#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "ConnectorTemplate.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FConnectorTemplate {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> ClosedClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> OpenedClass;
    
    ROBOQUEST_API FConnectorTemplate();
};

