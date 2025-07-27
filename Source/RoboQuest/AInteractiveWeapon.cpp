#include "AInteractiveWeapon.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ParticleSystemComponent -FallbackName=ParticleSystemComponent
#include "Particles/ParticleSystemComponent.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SkeletalMeshComponent -FallbackName=SkeletalMeshComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=UMG -ObjectName=WidgetComponent -FallbackName=WidgetComponent
#include "Net/UnrealNetwork.h"

AAInteractiveWeapon::AAInteractiveWeapon(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
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


