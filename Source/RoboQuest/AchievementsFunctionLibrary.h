#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BlueprintFunctionLibrary -FallbackName=BlueprintFunctionLibrary
#include "BlueprintAchievement.h"
#include "AchievementsFunctionLibrary.generated.h"

class APlayerController;
class UObject;

UCLASS(Blueprintable)
class ROBOQUEST_API UAchievementsFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UAchievementsFunctionLibrary();

private:
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static TArray<FBlueprintAchievement> GetCachedAchievementsForLocalPlayer(const UObject* WorldContextObject, APlayerController* PlayerController);
    
};

