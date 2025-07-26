#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
#include "AArenaTile.h"
#include "ATutoArenaTile.generated.h"

class UTexture2D;

UCLASS(Abstract, Blueprintable)
class ROBOQUEST_API AATutoArenaTile : public AAArenaTile {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* BasecampMapTexture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D BasecampMapOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BasecampMapAngle;
    
    AATutoArenaTile(const FObjectInitializer& ObjectInitializer);

};

