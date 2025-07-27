#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=GameViewportClient -FallbackName=GameViewportClient
#include "AGameViewportClient.generated.h"

UCLASS(Blueprintable, NonTransient)
class ROBOQUEST_API UAGameViewportClient : public UGameViewportClient {
    GENERATED_BODY()
public:
    UAGameViewportClient();

};

