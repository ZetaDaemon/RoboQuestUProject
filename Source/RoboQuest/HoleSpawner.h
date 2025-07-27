#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "HoleSpawner.generated.h"

class AAHoleSpawner;
class AActor;

USTRUCT(BlueprintType)
struct FHoleSpawner {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AAHoleSpawner> Opened;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<AAHoleSpawner> OpenedClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> Closed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> ClosedClass;
    
    ROBOQUEST_API FHoleSpawner();
};

