#pragma once
#include "CoreMinimal.h"
#include "AInteractive.h"
#include "AInteractiveSecretRuins.generated.h"

UCLASS(Blueprintable)
class ROBOQUEST_API AAInteractiveSecretRuins : public AAInteractive {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 ID;
    
    AAInteractiveSecretRuins(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnLevelGenerationFinished(const FName& LevelRowName);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintValidate();
    
};

