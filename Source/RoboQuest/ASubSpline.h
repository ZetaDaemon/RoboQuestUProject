#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include "ASubSpline.generated.h"

class USceneComponent;

UCLASS(Blueprintable)
class ROBOQUEST_API AASubSpline : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    AASubSpline(const FObjectInitializer& ObjectInitializer);

};

