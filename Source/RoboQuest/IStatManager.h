#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Interface -FallbackName=Interface
#include "EStat.h"
#include "StatValues.h"
#include "IStatManager.generated.h"

class UAStatManager;

UINTERFACE(BlueprintType, meta=(CannotImplementInterfaceInBlueprint))
class UIStatManager : public UInterface {
    GENERATED_BODY()
};

class IIStatManager : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable)
    virtual bool RestoreStat(EStat enumStat, float Modifier) PURE_VIRTUAL(RestoreStat, return false;);
    
    UFUNCTION(BlueprintCallable)
    virtual bool ReduceStat(EStat enumStat, float Modifier) PURE_VIRTUAL(ReduceStat, return false;);
    
    UFUNCTION()
    virtual void OnNotifyStatFull(EStat enumStat) PURE_VIRTUAL(OnNotifyStatFull,);
    
    UFUNCTION()
    virtual void OnNotifyStatEmpty(EStat enumStat) PURE_VIRTUAL(OnNotifyStatEmpty,);
    
    UFUNCTION()
    virtual void OnNotifyStat(EStat enumStat, float curVal, float Value) PURE_VIRTUAL(OnNotifyStat,);
    
    UFUNCTION(BlueprintCallable)
    virtual void MinimiseStat(EStat enumStat) PURE_VIRTUAL(MinimiseStat,);
    
    UFUNCTION(BlueprintCallable)
    virtual void MaximiseStat(EStat enumStat) PURE_VIRTUAL(MaximiseStat,);
    
    UFUNCTION(BlueprintCallable)
    virtual bool HaveStat(EStat enumStat) const PURE_VIRTUAL(HaveStat, return false;);
    
    UFUNCTION(BlueprintCallable)
    virtual float GetStatValue(EStat enumStat) const PURE_VIRTUAL(GetStatValue, return 0.0f;);
    
    UFUNCTION(BlueprintCallable)
    virtual FStatValues GetStatStruct(EStat enumStat) const PURE_VIRTUAL(GetStatStruct, return FStatValues{};);
    
    UFUNCTION(BlueprintCallable)
    virtual UAStatManager* GetStatManager() const PURE_VIRTUAL(GetStatManager, return NULL;);
    
    UFUNCTION(BlueprintCallable)
    virtual float GetStatCurrentValue(EStat enumStat) const PURE_VIRTUAL(GetStatCurrentValue, return 0.0f;);
    
    UFUNCTION(BlueprintCallable)
    virtual float GetMoveStatValue(float InitialValue) const PURE_VIRTUAL(GetMoveStatValue, return 0.0f;);
    
};

