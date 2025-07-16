#pragma once
#include "CoreMinimal.h"
#include "PoolDecalComponent.h"
#include "HitDecalComponent.generated.h"

class UASkill;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROBOQUEST_API UHitDecalComponent : public UPoolDecalComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UASkill* Skill;
    
public:
    UHitDecalComponent(const FObjectInitializer& ObjectInitializer);

};

