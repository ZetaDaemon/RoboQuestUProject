#pragma once
#include "CoreMinimal.h"
#include "ADestructible.h"
#include "ADestructibleSM.generated.h"

class UStaticMeshComponent;

UCLASS(Abstract, Blueprintable)
class ROBOQUEST_API AADestructibleSM : public AADestructible {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* DestructibleSM;
    
    AADestructibleSM(const FObjectInitializer& ObjectInitializer);

};

