#pragma once
#include "CoreMinimal.h"
#include "ASpawnPoint.h"
#include "ABossPoint.generated.h"

class UTexture2D;

UCLASS(Abstract, Blueprintable)
class ROBOQUEST_API AABossPoint : public AASpawnPoint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* SelfIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* IndieIcon;
    
    AABossPoint(const FObjectInitializer& ObjectInitializer);

};

