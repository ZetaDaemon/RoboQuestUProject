#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include "SpecialIndicatorBloc.generated.h"

class UBillboardComponent;
class USceneComponent;

UCLASS(Blueprintable)
class ROBOQUEST_API ASpecialIndicatorBloc : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBillboardComponent* Icon;
    
    ASpecialIndicatorBloc(const FObjectInitializer& ObjectInitializer);

};

