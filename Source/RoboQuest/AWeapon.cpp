#include "AWeapon.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=AudioComponent -FallbackName=AudioComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SkeletalMeshComponent -FallbackName=SkeletalMeshComponent
#include "ASkillManager.h"
#include "AStatManager.h"
#include "Net/UnrealNetwork.h"

AAWeapon::AAWeapon(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->RootComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
    this->isEquiped = false;
    this->bInitialWeapon = false;
    this->bNeedReload = false;
    this->CharacterOwner = NULL;
    this->bExcludeForSuperbot = false;
    this->FeedbackMuzzleScale = 0.00f;
    this->DT_WeaponAffix = NULL;
    this->DT_WeaponMod = NULL;
    this->bOneHand = false;
    this->bHeavy = false;
    this->WeaponStatManager = CreateDefaultSubobject<UAStatManager>(TEXT("WeaponStatManager"));
    this->WeaponSkillManager = CreateDefaultSubobject<UASkillManager>(TEXT("WeaponSkillManager"));
    this->RandomAffixesRarity[0] = 0;
    this->RandomAffixesRarity[1] = 0;
    this->RandomAffixesRarity[2] = 0;
    this->Mesh = (USkeletalMeshComponent*)RootComponent;
    this->LootCategory = EWeaponCategory::Assault;
    this->Icon = NULL;
    this->ReloadSound = NULL;
    this->HapticReloadSound = NULL;
    this->AnimClass = NULL;
    this->HandPoseType = EAnimPose::T00;
    this->CoolingSpeedRatioByAmmo = NULL;
    this->UpgradePriceReduction = 0;
    this->WarmupFirerateModifier = NULL;
    this->WarmupDuration = 0.00f;
    this->bCoolingWeapon = false;
    this->CurrentRecoilRecoverySpeed = 0.00f;
    this->RecoilRecoveryMultiplierPerSecond = 0.00f;
    this->MaxRecoilRecoverySpeed = 0.00f;
    this->RecoilRecoverySpeed = 0.00f;
    this->EnergizedReloadSpeed = 0.00f;
    this->EnergizedFirerate = 0.00f;
    this->EnergizedDuration = 0.00f;
    this->IdleSound = NULL;
    this->IdleSoundComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("IdleSoundComponent"));
    this->PickupMeshPose = NULL;
    this->PickupOverrideMesh = NULL;
    this->bIsInitialized = false;
    this->TemporaryMaterial = NULL;
    this->OverridePlayerReloadFPV = NULL;
    this->OverridePlayerReloadTPV = NULL;
    this->OverrideWeaponReloadFPV = NULL;
    this->OverrideWeaponReloadTPV = NULL;
    this->OverridePlayerHighCoolingReloadFPV = NULL;
    this->OverridePlayerLowCoolingReloadFPV = NULL;
    this->OverrideWeaponHighCoolingReloadFPV = NULL;
    this->OverrideWeaponLowCoolingReloadFPV = NULL;
    this->OverridePlayerHighCoolingReloadTPV = NULL;
    this->OverrideWeaponHighCoolingReloadTPV = NULL;
    this->OverrideMesh = NULL;
    this->OverrideOverheatFX = NULL;
    this->bScope = false;
    this->bCanShotWhileScopped = false;
    this->WeaponElement = EElement::LastIndex;
    this->bSecondaryFireCancelAction = true;
    this->Level = 0;
    this->bThrowable = true;
    this->PocketReloadRatio = 1.00f;
    this->bCalculatePocketReload = false;
    this->WarmupLoopAudioComponent = NULL;
    this->WarmupStartSound = NULL;
    this->WarmupLoopSound = NULL;
    this->WarmupStopSound = NULL;
    this->SpreadModifier = 1.00f;
    this->SpreadIncreaseCurve = 0.00f;
    this->MaxOverheat = 100.00f;
    this->StartOverheatSound = NULL;
    this->StartOverheatHapticSound = NULL;
    this->LoopOverheatSound = NULL;
    this->bRecoverCooling = false;
    this->bCoolingOverheat = false;
    this->CoolingOverheatDuration = 0.00f;
    this->CoolingOverheatRecoverSpeedRatio = 1.00f;
    this->OverheatFX = NULL;
    this->OverheatFXRef = NULL;
    this->DualOverheatFXRef = NULL;
    this->DamagePower = 0;
    this->SpeedPower = 0;
    this->bExcludeForRandomEliteAffix = false;
    this->LootLevel = 0;
    this->AffixAmount = 0;
    this->AffixEliteLuckLevel = 0;
    this->WeaponModIcon = NULL;
    this->BaseRandomSeed = 0;
    this->GameStateRef = NULL;
    this->GameModeRef = NULL;
    this->GameInstanceRef = NULL;
    this->CreationTime = 1750726445196;
    this->IdleSoundComponent->SetupAttachment(RootComponent);
}

void AAWeapon::UpgradeWeaponAffixQuality() {
}

void AAWeapon::UpdateWeaponMaterialParameter(const FName& ParameterName, float Value) {
}

void AAWeapon::UpdateSpreadModifier(float NewSpreadModifier) {
}

void AAWeapon::StoreMonitoringTimer(const FString& Context, bool bPrint) {
}

void AAWeapon::StartMaterialProcEffect_Implementation(EWeaponProcType Type) {
}

void AAWeapon::SpawnGunEffectParticle(UParticleSystem* InParticle) {
}

void AAWeapon::SetWeaponVisibility_Implementation(bool bNewVisibility) {
}

void AAWeapon::SetWeaponLevel(int32 NewLevel) {
}

void AAWeapon::SetWeaponElement_Implementation(EElement Element) {
}

void AAWeapon::SetWeaponCurrent_Implementation(bool bIsCurrent) {
}

void AAWeapon::SetVectorDynamicParameter(FName ParameterName, FVector Value) {
}

void AAWeapon::SetSecondaryFireCancelAction(bool bCancelAction) {
}

void AAWeapon::SetScalarDynamicParameter(FName ParameterName, float Value) {
}

void AAWeapon::SetNewWeaponMaterials(UMaterialInstanceDynamic* NewMaterial) {
}

void AAWeapon::SetNewSpreadClamp(FVector2D NewSpreadClamp) {
}

void AAWeapon::SetBoneHidden(FName BoneName, bool bNewHidden) {
}

void AAWeapon::ResetWeaponMaterials() {
}

void AAWeapon::RerollRandomAffixes(bool bKeepAffixBundle) {
}

void AAWeapon::RepNotify_CharacterOwner() {
}

void AAWeapon::RemoveWeaponElement_Implementation(EElement Element) {
}

void AAWeapon::RemoveSuperFeedback() {
}

void AAWeapon::RemoveStatModifier(UModifier_Stat* Modifier) {
}

void AAWeapon::RemoveSpeedPower() {
}

void AAWeapon::RemoveScopeState() {
}

void AAWeapon::RemoveInfiniteClip() {
}

void AAWeapon::RemoveEliteAffixe() {
}

void AAWeapon::RemoveDamagePower() {
}

void AAWeapon::RemoveDamageModifier(UModifier_Damage* Modifier) {
}


void AAWeapon::OnSwitch_Implementation() {
}

void AAWeapon::OnServerApplyReload_Implementation() {
}
bool AAWeapon::OnServerApplyReload_Validate() {
    return true;
}

void AAWeapon::OnNotifyStatFull(EStat enumStat) {
}

void AAWeapon::OnNotifyStatEmpty(EStat enumStat) {
}

void AAWeapon::OnNotifyStat(EStat enumStat, float curVal, float Value) {
}

void AAWeapon::OnMulticastApplyReload_Implementation() {
}

void AAWeapon::OnEndSwitchReload() {
}

void AAWeapon::OnCommonWeaponDataAssetLoaded() {
}







void AAWeapon::LevelUpWeapon() {
}

bool AAWeapon::IsLocallyControlled() {
    return false;
}

bool AAWeapon::IsCurrentWeapon() const {
    return false;
}

void AAWeapon::InitWeaponSavedData() {
}

void AAWeapon::InitInfiniteClip() {
}

void AAWeapon::InitializeAffixe(const FName& RowName, EWeaponAffixType Type) {
}

FText AAWeapon::GetWeaponName() const {
    return FText::GetEmpty();
}

float AAWeapon::GetWeaponBaseStat(EStat Stat, EAction Action, ACharacter_Player* PlayerRef, bool bMultiHitPacked) {
    return 0.0f;
}

float AAWeapon::GetWarmupRegenDuration() {
    return 0.0f;
}

float AAWeapon::GetWarmupDuration() {
    return 0.0f;
}

int32 AAWeapon::GetSeededRandomRange(int32 Min, int32 Max, const FString& Context) {
    return 0;
}

FString AAWeapon::GetRandomAffixString() {
    return TEXT("");
}

FName AAWeapon::GetMuzzleSocketName(int32 Index) const {
    return NAME_None;
}

UTexture2D* AAWeapon::GetModIcon() {
    return NULL;
}

float AAWeapon::GetMinSpread() {
    return 0.0f;
}

float AAWeapon::GetMaxSpread() {
    return 0.0f;
}

UAnimSequence* AAWeapon::GetHandPose(bool bWantLeft, bool bTPV) const {
    return NULL;
}

TArray<EGameplayTags> AAWeapon::GetGameplayTagList() {
    return TArray<EGameplayTags>();
}

FString AAWeapon::GetDisplayName() const {
    return TEXT("");
}

FName AAWeapon::GetDataRowName() const {
    return NAME_None;
}

float AAWeapon::GetCustomFloatProperty(const FName& PropertyName) const {
    return 0.0f;
}

float AAWeapon::GetCurrentSpread() {
    return 0.0f;
}

float AAWeapon::GetCurrentRecoil() {
    return 0.0f;
}

FName AAWeapon::GetCurrentEnchantedAffixRowName() {
    return NAME_None;
}


float AAWeapon::GetCoolingRatio() const {
    return 0.0f;
}


FLinearColor AAWeapon::GetCoolingColor() {
    return FLinearColor{};
}

ACharacter_Player* AAWeapon::GetCharacter() {
    return NULL;
}

EWeaponAffixRarity AAWeapon::GetBestAffixRarity() {
    return EWeaponAffixRarity::Common;
}

TArray<EGameplayTags> AAWeapon::GetBaseGameplayTagList() {
    return TArray<EGameplayTags>();
}

UAnimInstance* AAWeapon::GetAnimInstanceByType(EAnimationType Type) {
    return NULL;
}

TArray<FName> AAWeapon::GetAffixRowNames(EWeaponAffixType Type) {
    return TArray<FName>();
}

bool AAWeapon::GetAffixRow(const FName& RowName, FWeaponAffix& OutWeaponAffix) const {
    return false;
}

int32 AAWeapon::GetAffixLevel() {
    return 0;
}

int32 AAWeapon::GetAffixAmountByRarity(EWeaponAffixRarity Rarity) {
    return 0;
}

void AAWeapon::ExtractDatatable() {
}

bool AAWeapon::CanReload() {
    return false;
}

void AAWeapon::CancelMaterialProcEffect_Implementation() {
}

void AAWeapon::ApplySuperFeedback() {
}

void AAWeapon::ApplyStatModifier(UModifier_Stat* Modifier) {
}

void AAWeapon::ApplyReload() {
}

void AAWeapon::ApplyDamageModifier(UModifier_Damage* Modifier) {
}

void AAWeapon::AddSpeedPower() {
}

FWeaponAffixRowHandle AAWeapon::AddRandomAffixe() {
    return FWeaponAffixRowHandle{};
}

void AAWeapon::AddEnchantedAffix(FName EnchantedAffixRowName) {
}

void AAWeapon::AddDamagePower() {
}

void AAWeapon::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AAWeapon, bInitialWeapon);
    DOREPLIFETIME(AAWeapon, CharacterOwner);
    DOREPLIFETIME(AAWeapon, Level);
    DOREPLIFETIME(AAWeapon, AffixAmount);
    DOREPLIFETIME(AAWeapon, AffixEliteLuckLevel);
    DOREPLIFETIME(AAWeapon, BaseRandomSeed);
    DOREPLIFETIME(AAWeapon, CreationTime);
}


