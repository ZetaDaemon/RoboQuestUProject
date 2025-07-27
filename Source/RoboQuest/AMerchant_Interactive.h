#pragma once
#include "CoreMinimal.h"
#include "AMerchant.h"
#include "AMerchant_Interactive.generated.h"

class UChildActorComponent;

UCLASS(Blueprintable)
class ROBOQUEST_API AAMerchant_Interactive : public AAMerchant {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UChildActorComponent* InteractChildActor;
    
    AAMerchant_Interactive(const FObjectInitializer& ObjectInitializer);

};

