#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SkeletalMeshComponent -FallbackName=SkeletalMeshComponent
#include "SkeletalMeshComponentWithMobility.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROBOQUEST_API USkeletalMeshComponentWithMobility : public USkeletalMeshComponent {
    GENERATED_BODY()
public:
    USkeletalMeshComponentWithMobility(const FObjectInitializer& ObjectInitializer);

};

