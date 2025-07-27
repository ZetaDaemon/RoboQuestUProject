#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=OnlineBlueprintCallProxyBase -FallbackName=OnlineBlueprintCallProxyBase
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "WritePlayerDataStorageFileDelegateDelegate.h"
#include "RQWritePlayerDataStorageFile.generated.h"

class APlayerController;
class UObject;
class URQWritePlayerDataStorageFile;

UCLASS(Blueprintable)
class ROBOQUEST_API URQWritePlayerDataStorageFile : public UOnlineBlueprintCallProxyBase {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWritePlayerDataStorageFileDelegate OnSuccess;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWritePlayerDataStorageFileDelegate OnFailure;
    
public:
    URQWritePlayerDataStorageFile();

private:
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static URQWritePlayerDataStorageFile* WritePlayerDataStorageFile(UObject* WorldContextObject, APlayerController* PlayerController, const FString& Filename, const TArray<uint8>& Data);
    
};

