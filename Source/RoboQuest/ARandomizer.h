#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include "ERandomLuck.h"
#include "ARandomizer.generated.h"

class USceneComponent;

UCLASS(Blueprintable)
class ROBOQUEST_API AARandomizer : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* RandomRoot;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERandomLuck Luck;
    
public:
    AARandomizer(const FObjectInitializer& ObjectInitializer);

};

