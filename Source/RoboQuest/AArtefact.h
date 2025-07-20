#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Vector_NetQuantize -FallbackName=Vector_NetQuantize
#include "AArtefact.generated.h"

class AActor;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROBOQUEST_API UAArtefact : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RandomSeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShouldTick;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RowName;
    
    UAArtefact(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStartReplicatedEffectWithBoolean(bool bState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStartReplicatedEffectOnTwoLocations(FVector_NetQuantize BaseLocation, FVector_NetQuantize Location);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStartReplicatedEffectOnLocation(FVector_NetQuantize Location);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStartReplicatedEffectOnActorAndLocation(AActor* Actor, FVector_NetQuantize Location);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStartReplicatedEffectOnActor(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStartReplicatedEffect();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnRemove();
    
};

