#pragma once
#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SaveGame -FallbackName=SaveGame
#include "ASaveGame.generated.h"

UCLASS(Blueprintable)
class ROBOQUEST_API UASaveGame : public USaveGame {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString SaveSlotName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 UserIndex;
    
    UASaveGame();

};

