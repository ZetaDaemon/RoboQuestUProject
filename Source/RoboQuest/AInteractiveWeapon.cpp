#include "AInteractiveWeapon.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ParticleSystemComponent -FallbackName=ParticleSystemComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SkeletalMeshComponent -FallbackName=SkeletalMeshComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=UMG -ObjectName=WidgetComponent -FallbackName=WidgetComponent
#include "Net/UnrealNetwork.h"

AAInteractiveWeapon::AAInteractiveWeapon(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
    this->Widget = CreateDefaultSubobject<UWidgetComponent>(TEXT("Widget"));
    this->WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
    this->WeaponBeam = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("WeaponBeam"));
    this->WeaponStar = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("WeaponStar"));
    this->WeaponMod = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("WeaponMod"));
    this->SpawnedWeapon = NULL;
    this->WeaponClass = NULL;
    this->WeaponLevel = 0;
    this->BaseRandomSeed = 0;
    this->AffixAmount = -1;
    this->MetaRewardModifier = EWeaponMetaRewardModifier::Base;
    this->TooltipRef = NULL;
    this->bDebugOffset = false;
    this->bInitialized = false;
    this->WeaponStarFX = NULL;
    this->WeaponModFX = NULL;
    this->WeaponStarDynamicMaterial = NULL;
    this->WeaponModDynamicMaterial = NULL;
    this->LootedSoundLoaded = NULL;
    this->bAlreadyInteracted = false;
    this->Scene->SetupAttachment(RootComponent);
    this->Widget->SetupAttachment(Scene);
    this->WeaponMesh->SetupAttachment(RootComponent);
    this->WeaponBeam->SetupAttachment(RootComponent);
    this->WeaponStar->SetupAttachment(Scene);
    this->WeaponMod->SetupAttachment(Scene);
}

void AAInteractiveWeapon::UpdateWeaponStarIcon() {
}

void AAInteractiveWeapon::UpdateWeaponModIcon() {
}

void AAInteractiveWeapon::UpdateBeamColor() {
}

void AAInteractiveWeapon::SetWeaponElement(EElement Element) {
}

void AAInteractiveWeapon::SetScreenshotMode(bool bScreenshotMode) {
}

void AAInteractiveWeapon::RepNotify_SpawnedWeapon() {
}

void AAInteractiveWeapon::OnWeaponUpdateAffix() {
}

void AAInteractiveWeapon::OnWeaponSpawned() {
}

void AAInteractiveWeapon::OnWeaponLevelUp(int32 NewLevel) {
}

void AAInteractiveWeapon::OnWeaponInitialize(AAWeapon* Weapon) {
}

void AAInteractiveWeapon::OnUpdateLocalization(const FString& NewLanguage) {
}

void AAInteractiveWeapon::OnEndTimerDestroyBasecamp() {
}

void AAInteractiveWeapon::OnBoneHidden(const FName& BoneName, bool bNewHidden) {
}


bool AAInteractiveWeapon::IsExcludedForSuperbot(FText& ExcludeText) const {
    return false;
}

FTransform AAInteractiveWeapon::GetMeshTransformByType(EAnimPose animPose) const {
    return FTransform{};
}

void AAInteractiveWeapon::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AAInteractiveWeapon, SpawnedWeapon);
}


