#pragma once
#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "SpecialTriggerBoxComponent.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROBOQUEST_API USpecialTriggerBoxComponent : public UBoxComponent {
    GENERATED_BODY()
public:
    USpecialTriggerBoxComponent(const FObjectInitializer& ObjectInitializer);

};

