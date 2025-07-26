#pragma once
#include "CoreMinimal.h"
#include "ABossTile.h"
#include "AMoonBossTile.generated.h"

UCLASS(Blueprintable)
class ROBOQUEST_API AAMoonBossTile : public AABossTile {
    GENERATED_BODY()
public:
    AAMoonBossTile(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void PreStartLastMoonBossCombat();
    
    UFUNCTION(BlueprintCallable)
    void PostStartLastMoonBossCombat();
    
};

