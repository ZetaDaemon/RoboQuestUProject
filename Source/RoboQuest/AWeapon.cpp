#include "AWeapon.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=AudioComponent -FallbackName=AudioComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SkeletalMeshComponent -FallbackName=SkeletalMeshComponent
#include "ASkillManager.h"
#include "AStatManager.h"
#include "Net/UnrealNetwork.h"

AAWeapon::AAWeapon(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
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


