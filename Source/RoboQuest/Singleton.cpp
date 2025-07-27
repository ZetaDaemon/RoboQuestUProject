#include "Singleton.h"

USingleton::USingleton() {
}

void USingleton::OnTrapEndPlay(AActor* Actor, const TEnumAsByte<EEndPlayReason::Type> EndPlayReason) {
}

bool USingleton::IsValidNavLocation(const FVector& Location, FVector& ProjectedLocationOnNavMesh) const {
    return false;
}

bool USingleton::IsEnemyGenerationDisabled() const {
    return false;
}

bool USingleton::HaveLocalizationWarning(ELocalization InLocalization) const {
    return false;
}

UTexture2D* USingleton::GetWeaponStarIcon(int32 Level) {
    return NULL;
}

FText USingleton::GetWeaponRarityName(EWeaponColor Color) const {
    return FText::GetEmpty();
}

float USingleton::GetWeaponProcIntensity(EWeaponProcType Type) const {
    return 0.0f;
}

FLinearColor USingleton::GetWeaponProcColor(EWeaponProcType Type) const {
    return FLinearColor{};
}

int32 USingleton::GetWeaponPrice(EWeaponColor InWeaponColor) const {
    return 0;
}

FTransform USingleton::GetWeaponMeshTransformByType(EAnimPose Type) const {
    return FTransform{};
}

FLinearColor USingleton::GetWeaponColor(EWeaponColor Color) const {
    return FLinearColor{};
}

TSoftObjectPtr<UParticleSystem> USingleton::GetWeaponAffixParticle(EWeaponAffixParticle InParticle) const {
    return NULL;
}

int32 USingleton::GetUpgradeWeaponPrice(EWeaponColor InWeaponColor) const {
    return 0;
}

int32 USingleton::GetUpgradeAffixQualityPrice(EWeaponColor InWeaponColor) const {
    return 0;
}

float USingleton::GetStatusDuration(EStatus Status) const {
    return 0.0f;
}

FText USingleton::GetSprintModeNames(ESprintMode InEnum) {
    return FText::GetEmpty();
}

FText USingleton::GetSettingsQualityWithoffNames(ESettingsQualityWithOff InEnum) {
    return FText::GetEmpty();
}

FText USingleton::GetSettingsQualityNames(ESettingsQuality InEnum) {
    return FText::GetEmpty();
}

FText USingleton::GetScopeModeNames(EScopeMode InEnum) {
    return FText::GetEmpty();
}

int32 USingleton::GetRerollAffixPrice(EWeaponColor InWeaponColor) const {
    return 0;
}

int32 USingleton::GetRerollAffixCost(int32 Level) {
    return 0;
}

uint8 USingleton::GetRandomizerPercentChances(ERandomLuck Luck) const {
    return 0;
}

float USingleton::GetMetaRewardsLevelPercent(int32 Level) const {
    return 0.0f;
}

float USingleton::GetMagnetismSettingSliderValue(float X) const {
    return 0.0f;
}

FText USingleton::GetLocalizationStatSuffix(EStatSuffix InEnum) {
    return FText::GetEmpty();
}

FText USingleton::GetLocalizationStatPrefixe(EStatPrefix InEnum) {
    return FText::GetEmpty();
}

FText USingleton::GetLocalizationSessionRegion(ESessionRegion InEnum) {
      return FText::GetEmpty();
}

FText USingleton::GetLocalizationNames(ELocalization InEnum) {
    return FText::GetEmpty();
}

FText USingleton::GetLocalizationControllerType(EController InEnum) {
    return FText::GetEmpty();
}

int32 USingleton::GetLevelUpWeaponWrenchCost(int32 Level, int32 WeaponLevel) {
    return 0;
}

TArray<FKeyword> USingleton::GetKeywordData(const UObject* WorldContextObject) {
    return TArray<FKeyword>();
}

UTexture2D* USingleton::GetKeyboardIcon(const FKey& Key) {
    return NULL;
}

int32 USingleton::GetItemPrice(EItemRarity InRarity) const {
    return 0;
}

float USingleton::GetInverseMagnetismSettingSliderValue(float Y) const {
    return 0.0f;
}

FText USingleton::GetGraphicQualityPresetNames(EGraphicQualityPreset InEnum) {
    return FText::GetEmpty();
}

FGraphicQuality USingleton::GetGraphicQualityPreset(EGraphicQualityPreset Preset) const {
    return FGraphicQuality{};
}

FGraphicConsole USingleton::GetGraphicQualityConsole() const {
    return FGraphicConsole{};
}

FVector2D USingleton::GetGarryRewardLuck(uint8 CurrentUseAmount) const {
    return FVector2D{};
}

TArray<EGarryReward> USingleton::GetGarryRewardByLuck(ERandomLuck RandomLuck) const {
    return TArray<EGarryReward>();
}

EGarryAnimation USingleton::GetGarryRewardAnimation(EGarryReward RewardType) const {
    return EGarryAnimation::Loose;
}

int32 USingleton::GetGarryPrice(uint8 CurrentUseAmount) const {
    return 0;
}

int32 USingleton::GetFPSLimitOnConsole() const {
    return 0;
}

FName USingleton::GetEmptyItemRow(EItemRarity InRarity) const {
    return NAME_None;
}

FText USingleton::GetDisplayModeNames(EDisplayMode InEnum) {
    return FText::GetEmpty();
}

TSoftObjectPtr<UTexture2D> USingleton::GetCustomCostIcon(ECustomCost Type) const {
    return NULL;
}

FText USingleton::GetCrouchModeNames(ECrouchMode InEnum) {
    return FText::GetEmpty();
}

FText USingleton::GetCrosshairModeNames(ECrosshairMode InEnum) {
    return FText::GetEmpty();
}

FText USingleton::GetCrosshairColorNames(ECrosshairColor InEnum) {
    return FText::GetEmpty();
}

FLinearColor USingleton::GetCrosshairColor(ECrosshairColor InEnum) {
    return FLinearColor{};
}

FText USingleton::GetCreditCategory(ECreditCategory InEnum) {
    return FText::GetEmpty();
}

UTexture2D* USingleton::GetControllerIcon(EController Controller, const FKey& Key) {
    return NULL;
}

FText USingleton::GetColorBlindNames(EColorBlindType InEnum) {
    return FText::GetEmpty();
}

TArray<ECasinoLoot> USingleton::GetCasinoLootPool(int32 CasinoLevel) {
    return TArray<ECasinoLoot>();
}

int32 USingleton::GetCasinoLootAmountByType(int32 CasinoLevel, ECasinoLoot CasinoLootType) {
    return 0;
}

FText USingleton::GetAutoReloadModeNames(EAutoReloadMode InEnum) {
    return FText::GetEmpty();
}

FText USingleton::GetAspectRatioNames(EAspectRatio InEnum) {
    return FText::GetEmpty();
}

FText USingleton::GetAntiAlliasingNames(EAntiAlliasing InEnum) {
    return FText::GetEmpty();
}

FText USingleton::GetAnisotropyNames(EAnisotropy InEnum) {
    return FText::GetEmpty();
}

FLinearColor USingleton::GetAffixColorByRarity(EWeaponAffixRarity Rarity) {
    return FLinearColor{};
}

void USingleton::GenerateKeywordData(const UObject* WorldContextObject) {
}


