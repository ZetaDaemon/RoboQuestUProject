#pragma once
#include "CoreMinimal.h"
#include "AInteractive.h"
#include "AInteractive_PNJ.generated.h"

class USkeletalMeshComponent;

UCLASS(Blueprintable)
class ROBOQUEST_API AAInteractive_PNJ : public AAInteractive {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<float> UROVisibleDistanceFactorThesholds;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* SkeletalMeshComponent;
    
public:
    AAInteractive_PNJ(const FObjectInitializer& ObjectInitializer);

};

