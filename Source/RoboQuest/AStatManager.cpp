#include "AStatManager.h"
#include "Net/UnrealNetwork.h"

UAStatManager::UAStatManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bIsAutoRecord = false;
    this->targetInterface = NULL;
    this->bInitialized = false;
    this->bHitFeedback = false;
    this->bHitFeedbackAlive = false;
    this->bHealthBar = false;
    this->HealthBarComponent = NULL;
    this->bFloatingText = false;
    this->FloatingTextComponent = NULL;
}

void UAStatManager::UpdateStatusDuration(EStatus Status, float AddValue) {
}

void UAStatManager::StartHitFeedback() {
}

void UAStatManager::SpawnHealthBarComponent() {
}

void UAStatManager::SpawnFloatingText(const FRQDamageInfo& DamageInfo) {
}

void UAStatManager::SetupHealthBar(UHealthBarWidget* HealthBar) {
}

void UAStatManager::SetStatValue(EStat enumStat, float NewValue, bool KeepCurrentRatio) {
}

void UAStatManager::SetStatusDuration(EStatus Status, float NewValue) {
}

void UAStatManager::SetMeshMaterialParameter(const FName& ParameterName, float Value) {
}

void UAStatManager::SetHealthBarSize(float NewSize) {
}

bool UAStatManager::RestoreStat(EStat enumStat, float Modifier) {
    return false;
}

void UAStatManager::RepNotify_TargetInterface() {
}

void UAStatManager::RepNotify_StatList() {
}

void UAStatManager::RemoveStat(EStat Stat) {
}

void UAStatManager::RemoveModifier(UModifier_Stat* Modifier) {
}

bool UAStatManager::ReduceStat(EStat enumStat, float Modifier) {
    return false;
}

void UAStatManager::OnServerSetStat_Implementation(EStat enumStat, const FStat& Stat) {
}
bool UAStatManager::OnServerSetStat_Validate(EStat enumStat, const FStat& Stat) {
    return true;
}

void UAStatManager::OnOwnerTakeDamage(const FRQDamageInfo& DamageInfo) {
}

void UAStatManager::OnOwnerDeath(const FRQDamageInfo& DamageInfo) {
}

void UAStatManager::OnModifierUpdated(EStat Stat, EModifierStatType Type, float Reliquat) {
}

void UAStatManager::OnGlobalModifierUpdated(EStat Stat) {
}

void UAStatManager::OnEndTimerHitFeedback() {
}


void UAStatManager::MinimiseStat(EStat enumStat) {
}

void UAStatManager::MaximiseStat(EStat enumStat) {
}

bool UAStatManager::IsFullStat(EStat enumStat) const {
    return false;
}

void UAStatManager::Initialize() {
}

bool UAStatManager::HaveStat(EStat enumStat) const {
    return false;
}

bool UAStatManager::HaveGlobalModifier() {
    return false;
}

float UAStatManager::GetTotalDotsDamage() {
    return 0.0f;
}

float UAStatManager::GetTotalDotDamage(EDot Dot) {
    return 0.0f;
}

float UAStatManager::GetStatValue(EStat enumStat) const {
    return 0.0f;
}

float UAStatManager::GetStatusDuration(EStatus Status) {
    return 0.0f;
}

FStatValues UAStatManager::GetStatStruct(EStat enumStat) const {
    return FStatValues{};
}

float UAStatManager::GetStatInitialValue(EStat enumStat) const {
    return 0.0f;
}

float UAStatManager::GetStatCurrentValue(EStat enumStat) const {
    return 0.0f;
}

float UAStatManager::GetStatBaseValue(EStat enumStat) const {
    return 0.0f;
}

FModifierValue UAStatManager::GetModifierValue(EStat TargetStat, bool bBaseValue) const {
    return FModifierValue{};
}

float UAStatManager::GetModifiedValue(EStat TargetStat, float InitialValue, bool bBaseValue) const {
    return 0.0f;
}

float UAStatManager::GetHealthBarSize() const {
    return 0.0f;
}

UHealthBarWidget* UAStatManager::GetHealthBar() const {
    return NULL;
}

UAGameInstance* UAStatManager::GetGameInstanceRef() {
    return NULL;
}

void UAStatManager::ConsumeDot(AActor* Instigator, float DamageModifier, EDot Dot) {
}

bool UAStatManager::CanStopTick() const {
    return false;
}

void UAStatManager::AttachFloatingTextComponent() {
}

void UAStatManager::ApplyModifier(UModifier_Stat* NewModifier) {
}

void UAStatManager::ApplyDotToTarget(AActor* Instigator, float Damage, EDot Dot) {
}

void UAStatManager::AddStat(FStat Stat) {
}

void UAStatManager::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UAStatManager, targetInterface);
}


