#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Color -FallbackName=Color
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Rotator -FallbackName=Rotator
#include "ASpawnPoint.h"
#include "EDirection.h"
#include "ESquadPointTag.h"
#include "ESquadPointType.h"
#include "HoloMesh.h"
#include "SquadPointIcons.h"
#include "ASquadPoint.generated.h"

UCLASS(Abstract, Blueprintable)
class ROBOQUEST_API AASquadPoint : public AASpawnPoint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESquadPointType PointType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bForceCenterEncounter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESquadPointTag PointTag;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FSquadPointIcons Icons[3];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FColor TagTextColors[3];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FHoloMesh HoloMeshes[3];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsInConnector;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDirection ConnectorDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator Rotation;
    
    AASquadPoint(const FObjectInitializer& ObjectInitializer);

};

