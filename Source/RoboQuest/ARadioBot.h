#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include "ARadioBot.generated.h"

class UAudioComponent;

UCLASS(Blueprintable)
class ROBOQUEST_API AARadioBot : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UAudioComponent*> AudioComponents;
    
    AARadioBot(const FObjectInitializer& ObjectInitializer);

};

