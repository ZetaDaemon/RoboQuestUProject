#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=OnlineBlueprintCallProxyBase -FallbackName=OnlineBlueprintCallProxyBase
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "EBPFileReadStorageType.h"
#include "ReadPlayerDataStorageFileDelegateDelegate.h"
#include "RQReadPlayerDataStorageFile.generated.h"

class APlayerController;
class UObject;
class URQReadPlayerDataStorageFile;

UCLASS(Blueprintable)
class ROBOQUEST_API URQReadPlayerDataStorageFile : public UOnlineBlueprintCallProxyBase {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FReadPlayerDataStorageFileDelegate OnSuccess;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FReadPlayerDataStorageFileDelegate OnFailure;
    
public:
    URQReadPlayerDataStorageFile();

private:
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static URQReadPlayerDataStorageFile* ReadPlayerDataStorageFile(UObject* WorldContextObject, APlayerController* PlayerController, const FString& Filename, EBPFileReadStorageType StorageType);
    
};

