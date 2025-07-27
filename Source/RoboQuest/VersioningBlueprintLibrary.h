#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BlueprintFunctionLibrary -FallbackName=BlueprintFunctionLibrary
#include "VersioningBlueprintLibrary.generated.h"

UCLASS(Blueprintable)
class UVersioningBlueprintLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UVersioningBlueprintLibrary();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString GetVersion_NoRevision();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString GetVersion();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetSVNRevision();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetPatchVersion();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetMinorVersion();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetMajorVersion();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetGameID();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString GetBuildID();
    
};

