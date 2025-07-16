#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=LinearColor -FallbackName=LinearColor
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "EDot.h"
#include "EElement.h"
#include "EModifierStatType.h"
#include "EStat.h"
#include "EStatus.h"
#include "ModifierValue.h"
#include "RQDamageInfo.h"
#include "Stat.h"
#include "StatValues.h"
#include "AStatManager.generated.h"

class AActor;
class UFloatingTextGeneratorComponent;
class UHealthBarComponent;
class UHealthBarWidget;
class UMaterialInstanceDynamic;
class UModifier_Stat;
class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROBOQUEST_API UAStatManager : public UActorComponent {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDelegateRepNotify, EStat, enumStat, float, curValue, float, Value);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnRemoveStat, EStat, enumStat);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDelegateNotifyOwner, EStat, enumStat, float, curValue, float, Value);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateNotifyFull, EStat, enumStat);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateNotifyEmpty, EStat, enumStat);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UModifier_Stat*> StoredModifiers;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateRepNotify DelegateRepNotify;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateNotifyFull DelegateNotifyFull;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateNotifyEmpty DelegateNotifyEmpty;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FStat> StatList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsAutoRecord;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=RepNotify_TargetInterface, meta=(AllowPrivateAccess=true))
    UObject* targetInterface;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInitialized;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<EElement> ElementalResistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInstanceDynamic*> DynamicMeshMaterials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor BaseColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor BurnColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHitFeedback;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHitFeedbackAlive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UHealthBarComponent> HealthBarComponentClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHealthBar;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UHealthBarComponent* HealthBarComponent;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UFloatingTextGeneratorComponent> FloatingTextComponentClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFloatingText;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UFloatingTextGeneratorComponent* FloatingTextComponent;
    
public:
    UAStatManager(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void UpdateStatusDuration(EStatus Status, float AddValue);
    
    UFUNCTION(BlueprintCallable)
    void StartHitFeedback();
    
    UFUNCTION(BlueprintCallable)
    void SpawnHealthBarComponent();
    
    UFUNCTION(BlueprintCallable)
    void SpawnFloatingText(const FRQDamageInfo& DamageInfo);
    
private:
    UFUNCTION(BlueprintCallable)
    void SetupHealthBar(UHealthBarWidget* HealthBar);
    
public:
    UFUNCTION(BlueprintCallable)
    void SetStatValue(EStat enumStat, float NewValue, bool KeepCurrentRatio);
    
    UFUNCTION(BlueprintCallable)
    void SetStatusDuration(EStatus Status, float NewValue);
    
    UFUNCTION(BlueprintCallable)
    void SetMeshMaterialParameter(const FName& ParameterName, float Value);
    
    UFUNCTION(BlueprintCallable)
    void SetHealthBarSize(float NewSize);
    
    UFUNCTION(BlueprintCallable)
    bool RestoreStat(EStat enumStat, float Modifier);
    
    UFUNCTION(BlueprintCallable)
    void RepNotify_TargetInterface();
    
    UFUNCTION(BlueprintCallable)
    void RepNotify_StatList();
    
    UFUNCTION(BlueprintCallable)
    void RemoveStat(EStat Stat);
    
    UFUNCTION(BlueprintCallable)
    void RemoveModifier(UModifier_Stat* Modifier);
    
    UFUNCTION(BlueprintCallable)
    bool ReduceStat(EStat enumStat, float Modifier);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerSetStat(EStat enumStat, const FStat& Stat);
    
    UFUNCTION(BlueprintCallable)
    void OnOwnerTakeDamage(const FRQDamageInfo& DamageInfo);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnOwnerDeath(const FRQDamageInfo& DamageInfo);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnModifierUpdated(EStat Stat, EModifierStatType Type, float Reliquat);
    
    UFUNCTION(BlueprintCallable)
    void OnGlobalModifierUpdated(EStat Stat);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnEndTimerHitFeedback();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintEndInitilization();
    
    UFUNCTION(BlueprintCallable)
    void MinimiseStat(EStat enumStat);
    
    UFUNCTION(BlueprintCallable)
    void MaximiseStat(EStat enumStat);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsFullStat(EStat enumStat) const;
    
    UFUNCTION(BlueprintCallable)
    void Initialize();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HaveStat(EStat enumStat) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HaveGlobalModifier();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetTotalDotsDamage();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetTotalDotDamage(EDot Dot);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetStatValue(EStat enumStat) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetStatusDuration(EStatus Status);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FStatValues GetStatStruct(EStat enumStat) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetStatInitialValue(EStat enumStat) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetStatCurrentValue(EStat enumStat) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetStatBaseValue(EStat enumStat) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FModifierValue GetModifierValue(EStat TargetStat, bool bBaseValue) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetModifiedValue(EStat TargetStat, float InitialValue, bool bBaseValue) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetHealthBarSize() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UHealthBarWidget* GetHealthBar() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAGameInstance* GetGameInstanceRef();
    
    UFUNCTION(BlueprintCallable)
    void ConsumeDot(AActor* Instigator, float DamageModifier, EDot Dot);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanStopTick() const;
    
    UFUNCTION(BlueprintCallable)
    void AttachFloatingTextComponent();
    
    UFUNCTION(BlueprintCallable)
    void ApplyModifier(UModifier_Stat* NewModifier);
    
    UFUNCTION(BlueprintCallable)
    void ApplyDotToTarget(AActor* Instigator, float Damage, EDot Dot);
    
    UFUNCTION(BlueprintCallable)
    void AddStat(FStat Stat);
    
};

