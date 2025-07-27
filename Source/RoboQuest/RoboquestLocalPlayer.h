#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=LocalPlayer -FallbackName=LocalPlayer
#include "RoboquestLocalPlayer.generated.h"

UCLASS(Blueprintable, NonTransient)
class ROBOQUEST_API URoboquestLocalPlayer : public ULocalPlayer {
    GENERATED_BODY()
public:
    URoboquestLocalPlayer();

};

