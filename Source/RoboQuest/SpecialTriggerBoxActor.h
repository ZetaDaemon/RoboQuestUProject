#pragma once
#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "SpecialTriggerBoxActor.generated.h"

class USpecialTriggerBoxComponent;

UCLASS(Blueprintable)
class ROBOQUEST_API ASpecialTriggerBoxActor : public ATriggerBox {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USpecialTriggerBoxComponent* RootSpecialTriggerBoxComponent;
    
    ASpecialTriggerBoxActor(const FObjectInitializer& ObjectInitializer);

};

