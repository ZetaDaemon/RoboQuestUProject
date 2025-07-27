#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=EComponentMobility -FallbackName=EComponentMobility
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SkeletalMeshActor -FallbackName=SkeletalMeshActor
#include "Animation/SkeletalMeshActor.h"
#include "SkeletalMeshActorWithMobility.generated.h"

UCLASS(Blueprintable)
class ROBOQUEST_API ASkeletalMeshActorWithMobility : public ASkeletalMeshActor {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EComponentMobility::Type> Mobility;
    
public:
    ASkeletalMeshActorWithMobility(const FObjectInitializer& ObjectInitializer);

};

