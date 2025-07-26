#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=HitResult -FallbackName=HitResult
#include "ATrap.h"
#include "ETeam.h"
#include "RQDamageInfo.h"
#include "ATrap_Overlap.generated.h"

class AActor;
class UBoxComponent;
class UPrimitiveComponent;

UCLASS(Blueprintable)
class ROBOQUEST_API AATrap_Overlap : public AATrap {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoxComponent* TriggerBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TriggerFirerate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExitOverlapDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreCapsuleWallCompensation;
    
    AATrap_Overlap(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void RefreshOverlapingActors();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnTriggerTrapEffect(AActor* InActor);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnTriggerBoxEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnTriggerBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    UFUNCTION(BlueprintCallable)
    void OnOverlappingActorDeath(const FRQDamageInfo& DamageInfo);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnDamageableActorBeginOverlap(AActor* InActor);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintRefresh();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<AActor*> GetOverlappingActorsByTeam(ETeam Team) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    TArray<UPrimitiveComponent*> GetOverlapComponents() const;
    
};

