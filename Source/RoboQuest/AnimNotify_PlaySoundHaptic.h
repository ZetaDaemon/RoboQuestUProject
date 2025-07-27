#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=AnimNotify -FallbackName=AnimNotify
#include "AnimNotify_PlaySoundHaptic.generated.h"

class USoundCue;

UCLASS(Blueprintable, CollapseCategories)
class ROBOQUEST_API UAnimNotify_PlaySoundHaptic : public UAnimNotify {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* SoundHaptic;
    
    UAnimNotify_PlaySoundHaptic();

};

