#pragma once
#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "Engine/TriggerBox.h"
#include "ABlockingBox.generated.h"

UCLASS(Blueprintable)
class ROBOQUEST_API AABlockingBox : public ATriggerBox {
    GENERATED_BODY()
public:
    AABlockingBox(const FObjectInitializer& ObjectInitializer);

};

