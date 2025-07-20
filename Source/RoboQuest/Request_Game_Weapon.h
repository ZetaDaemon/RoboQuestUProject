#pragma once
#include "CoreMinimal.h"
#include "Request_Game_Weapon.generated.h"

USTRUCT(BlueprintType)
struct FRequest_Game_Weapon {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Level;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Affix;
    
    ROBOQUEST_API FRequest_Game_Weapon();
};

