#pragma once
#include "CoreMinimal.h"
#include "Request_Game_Artefact.generated.h"

USTRUCT(BlueprintType)
struct FRequest_Game_Artefact {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
    ROBOQUEST_API FRequest_Game_Artefact();
};

