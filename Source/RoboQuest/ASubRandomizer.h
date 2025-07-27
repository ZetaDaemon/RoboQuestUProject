#pragma once
#include "CoreMinimal.h"
#include "ARandomizer.h"
#include "ASubRandomizer.generated.h"

UCLASS(Blueprintable)
class ROBOQUEST_API AASubRandomizer : public AARandomizer {
    GENERATED_BODY()
public:
    AASubRandomizer(const FObjectInitializer& ObjectInitializer);

};

