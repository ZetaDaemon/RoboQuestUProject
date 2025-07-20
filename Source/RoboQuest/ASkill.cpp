#include "ASkill.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"

UASkill::UASkill(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->TargetAction = EAction::LastIndex;
    this->RecordType = EInputRecordType::None;
    this->DT_PlayerSkills = NULL;
    this->DT_EnemySkill = NULL;
    this->DT_AllySkill = NULL;
    this->DT_ModSkills = NULL;
    this->ModifierWarmupFirerate = NULL;
    this->bBaseAreaOfEffect = false;
    this->bAreaOfEffect = false;
    this->bCanTriggerRocketJump = false;
    this->HealthPickupOnMeleeHitBossModifier = 0;
    this->GameplayTags = 0;
    this->bBeamFire = false;
    this->CharacterOwner = NULL;
    this->SpeedRatio = 1.00f;
    this->ModifierSpeedRatio = NULL;
    this->bIsInitialized = false;
    this->bIsPressed = false;
    this->bIsUsed = false;
    this->bRecoverCooldown = false;
    this->bAutoRecoverCooldown = true;
    this->CooldownSpeedRatio = 1.00f;
    this->bCustomStack = false;
    this->CurrentDuration = 0.00f;
    this->HitType = EHitType::Raycast;
    this->BaseHitType = EHitType::Raycast;
    this->bMultiHitLinked = false;
    this->bNoCollisionProjectile = false;
    this->RaycastBounceAmount = 0;
    this->Range = 0.00f;
    this->RangeRatio = 1.00f;
    this->RicochetAmount = 0;
    this->RicochetDamageRatio = 1.00f;
    this->TargetTeams = 0;
    this->ProjectileClass = NULL;
    this->ProjectileMesh = NULL;
    this->BaseProjectileMesh = NULL;
    this->ProjectileFX = NULL;
    this->BaseProjectileFX = NULL;
    this->TrailFX = NULL;
    this->BaseTrailFX = NULL;
    this->EndProjectileFX = NULL;
    this->ProjectileTravelSound = NULL;
    this->ProjectileSpeed = 0.00f;
    this->BaseProjectileSpeed = 0.00f;
    this->ProjectileBounceAmount = 0;
    this->ProjectileTickSound = NULL;
    this->ProjectileBounceSound = NULL;
    this->ProjectileBounceFX = NULL;
    this->bTriggerAreaOnBounce = false;
    this->ProjectileBounciness = 0.00f;
    this->ProjectileFriction = 0.00f;
    this->ProjectileGravityScale = 0.00f;
    this->BaseProjectileGravityScale = 0.00f;
    this->bTickProjectile = false;
    this->TickProjectileRadius = 0.00f;
    this->TickProjectileFirerate = 0.00f;
    this->bStickingProjectile = false;
    this->ProjectileTriggerType = EProjectileTriggerType::Time;
    this->ProjectileTriggerTime = 0.00f;
    this->ProjectileTriggerRange = 0.00f;
    this->bProjectileInstantCalculateRange = false;
    this->bHomingProjectile = false;
    this->HomingDelay = 0.00f;
    this->HomingRange = 0.00f;
    this->HomingAccelerationMagnitude = 0.00f;
    this->HomingDotTolerance = 0.00f;
    this->ProjectileLifetime = 0.00f;
    this->ProjectileCollisionSize = 0.00f;
    this->AreaSpawnPosition = ESpawnPosition::Around;
    this->ConeAngle = 0.00f;
    this->SphereRadius = 0.00f;
    this->ConeLength = 0.00f;
    this->bCustomTargetArea = false;
    this->AreaType = EAOEType::Box;
    this->bAllowHomingIfBouncing = false;
    this->CriticalModifier = NULL;
    this->AssaultModifier = NULL;
    this->CurveFallOffDamage = NULL;
    this->CurveFallOffImpactForce = NULL;
    this->CurveAreaBoneFallOff = NULL;
    this->DotDamageRatio = 0.00f;
    this->bAutoCritical = false;
    this->FriendlyDamage = 0.00f;
    this->IceRatio = 1.00f;
    this->ShockRatio = 1.00f;
    this->bSpreadPatternWithUseAmount = false;
    this->bSpreadPatternWithMuzzleIndex = false;
    this->RandomSeed = 0;
    this->MuzzleType = ESkillMuzzleType::All;
    this->CurrentMuzzle = 0;
    this->DamageType = EDamageType::Bullet;
    this->RagdollType = EKillRagdollType::Low;
    this->SuperFeedbackAmount = 0;
    this->MegaFeedbackAmount = 0;
    this->bDisplayOnlyFirstHitEvent = false;
    this->Type = ESkillBehavior::Fast;
    this->DeathFxByDamageType[0] = NULL;
    this->DeathFxByDamageType[1] = NULL;
    this->DeathFxByDamageType[2] = NULL;
    this->DeathFxByDamageType[3] = NULL;
    this->DeathFxByDamageType[4] = NULL;
    this->DeathFxByDamageType[5] = NULL;
    this->DeathFxByDamageType[6] = NULL;
    this->DeathFxByDamageType[7] = NULL;
    this->DeathFxByDamageType[8] = NULL;
    this->DeathFxByDamageType[9] = NULL;
    this->ExplosionByElement[0] = NULL;
    this->ExplosionByElement[1] = NULL;
    this->ExplosionByElement[2] = NULL;
    this->TrailByElement[0] = NULL;
    this->TrailByElement[1] = NULL;
    this->TrailByElement[2] = NULL;
    this->ProjectileParticleByElement[0] = NULL;
    this->ProjectileParticleByElement[1] = NULL;
    this->ProjectileParticleByElement[2] = NULL;
    this->ProjectileTrailByElement[0] = NULL;
    this->ProjectileTrailByElement[1] = NULL;
    this->ProjectileTrailByElement[2] = NULL;
    this->BashByElement[0] = NULL;
    this->BashByElement[1] = NULL;
    this->BashByElement[2] = NULL;
    this->bTriggerSurfaceEffect = false;
    this->MuzzleFX = NULL;
    this->BaseMuzzleFXScale = 1.00f;
    this->MuzzleFXScale = 0.00f;
    this->BaseHitFX = NULL;
    this->BaseDeathHitFX = NULL;
    this->HitFX = NULL;
    this->HitFXScale = 0.00f;
    this->DeathHitFX = NULL;
    this->DeathNoHitFX = NULL;
    this->RaycastTrailFX = NULL;
    this->BaseRaycastTrailFX = NULL;
    this->RaycastTrailEmiterBeamIndex.AddDefaulted(1);
    this->BaseAreaOfEffectFX = NULL;
    this->AreaOfEffectFX = NULL;
    this->AreaOfEffectHitFX = NULL;
    this->AreaDecalType = EAreaDecalMaterialTypes::NoDecal;
    this->AreaDecalFadeDuration = 0.00f;
    this->ImpactDecalType = ESkillImpactDecalTypes::NoDecal;
    this->DecalSize = 0.00f;
    this->ImpactHitFxComponent = NULL;
    this->EffectQuality = ESettingsQuality::Low;
    this->bIgnoreElementalProjectileFX = false;
    this->UseSound = NULL;
    this->bLoopSound = false;
    this->LoopSound = NULL;
    this->HapticLoopSound = NULL;
    this->StopSound = NULL;
    this->CancelSound = NULL;
    this->AreaOfEffectSound = NULL;
    this->BaseHitSound = NULL;
    this->HitSound = NULL;
    this->CurrentUseSound = NULL;
    this->LoopingSoundComponent = NULL;
    this->LoopingHapticSoundComponent = NULL;
    this->HoloMeshMaterial = NULL;
    this->bIsIgnoredByBarrier = false;
    this->InitialParticleSystemPoolCount[0] = 0;
    this->InitialParticleSystemPoolCount[1] = 0;
    this->InitialParticleSystemPoolCount[2] = 0;
    this->InitialParticleSystemPoolCount[3] = 0;
    this->InitialParticleSystemPoolCount[4] = 0;
    this->InitialParticleSystemPoolCount[5] = 0;
    this->InitialParticleSystemPoolCount[6] = 0;
    this->InitialParticleSystemPoolCount[7] = 0;
    this->MaxParticleSystemPoolCount[0] = 10;
    this->MaxParticleSystemPoolCount[1] = 10;
    this->MaxParticleSystemPoolCount[2] = 10;
    this->MaxParticleSystemPoolCount[3] = 10;
    this->MaxParticleSystemPoolCount[4] = 10;
    this->MaxParticleSystemPoolCount[5] = 10;
    this->MaxParticleSystemPoolCount[6] = 10;
    this->MaxParticleSystemPoolCount[7] = 10;
}

void UASkill::UseSkill() {
}

void UASkill::UpdateSpeedRatio(float NewSpeedRatio) {
}

void UASkill::UnregisterHitDecal(UHitDecalComponent* DecalComp) {
}

void UASkill::StartCooldownDelay() {
}

void UASkill::SpawnProjectiles(const FNetworkSkillInfo& NetworkInfo, const FNetworkSkillValues& NetworkSkillValues, float Speed, float GravityScale) {
}

TArray<AAProjectile*> UASkill::SpawnCustomProjectiles(const TArray<FNetworkSkillInfo>& NetworkInfos, float Speed, float GravityScale, FName CustomTag) {
    return TArray<AAProjectile*>();
}

void UASkill::SimulateTriggerAreaEffect(const FNetworkSkillInfo& NetworkInfo, AAProjectile* Projectile) {
}

void UASkill::SimulateReleased() {
}

void UASkill::SimulatePressed() {
}

void UASkill::SimulateCancel() {
}

void UASkill::SetSkillEnable_Implementation(bool bNewEnable) {
}

void UASkill::SetAreaSoundParameter_Implementation(UAudioComponent* InSound, AAProjectile* Projectile) {
}

void UASkill::ResetSkillRow() {
}

void UASkill::ResetProjectileClass() {
}

void UASkill::ResetCooldown() {
}

void UASkill::RemoveSuperTextFeedback() {
}

void UASkill::RemoveShockTag() {
}

void UASkill::RemovePierceState() {
}

void UASkill::RemoveMegaTextFeedback() {
}

void UASkill::RemoveImpactForceState() {
}

void UASkill::RemoveIceTag() {
}

void UASkill::RemoveGameplayTag(EGameplayTags Tag) {
}

void UASkill::RemoveExplosiveTag() {
}

void UASkill::RemoveDamageModifier(UModifier_Damage* Modifier) {
}

void UASkill::RemoveBurnTag() {
}

void UASkill::RemoveBounceState() {
}

void UASkill::ReduceCooldown(float ReduceTime) {
}

void UASkill::OnTriggerTarget_Implementation(const FRQDamageInfo& DamageInfo) {
}

void UASkill::OnTriggerSkillCustomEffect_Implementation(FNetworkSkillInfo NetworkInfo) {
}

void UASkill::OnTriggerPostSkillCustomEffect_Implementation(FNetworkSkillInfo NetworkInfo) {
}

void UASkill::OnTriggerKill_Implementation(const FRQDamageInfo& DamageInfo) {
}

void UASkill::OnSurfaceHitFxComponentFinished(UParticleSystemComponent* PSystem) {
}

void UASkill::OnSpawnProjectile_Implementation(AAProjectile* InProjectile, const FNetworkSkillInfo& NetworkInfo, const FNetworkSkillValues& NetworkSkillValues, float Speed, float GravityScale, FName CustomTag, int32 ProjectileIndex) {
}

void UASkill::OnSpawnMuzzleFX(UParticleSystemComponent* NewMuzzleFX) {
}

void UASkill::OnSkillEndInitialization_Implementation() {
}

void UASkill::OnServerCancelSkill_Implementation() {
}
bool UASkill::OnServerCancelSkill_Validate() {
    return true;
}

void UASkill::OnServerApplyDamages_Implementation(const TArray<FClientDamageInfo>& DamageInfos) {
}
bool UASkill::OnServerApplyDamages_Validate(const TArray<FClientDamageInfo>& DamageInfos) {
    return true;
}

void UASkill::OnServerApplyDamage_Implementation(const FClientDamageInfo& DamageInfo) {
}
bool UASkill::OnServerApplyDamage_Validate(const FClientDamageInfo& DamageInfo) {
    return true;
}

void UASkill::OnProjectileTick_Implementation(AAProjectile* Projectile) {
}

void UASkill::OnProjectileStartOverlap_Implementation(const FHitResult& HitResult, AAProjectile* Projectile) {
}


void UASkill::OnProjectileRicochet_Implementation(AActor* TargetCharacter, AAProjectile* Projectile) {
}

void UASkill::OnProjectileEndLife_Implementation(AAProjectile* Projectile) {
}

void UASkill::OnMulticastCancelSkill_Implementation() {
}

void UASkill::OnMulticastApplyDamages_Implementation(const TArray<FClientDamageInfo>& DamageInfos) {
}

void UASkill::OnMulticastApplyDamage_Implementation(const FClientDamageInfo& DamageInfo) {
}

void UASkill::OnGameStateDestroyed(AActor* Actor) {
}

void UASkill::OnDealCustomDamage(FHitResult HitResult, AAProjectile* Projectile) {
}

void UASkill::OnCommonSkillDataAssetLoaded() {
}





bool UASkill::OnBlueprintCanUseSkill_Implementation() {
    return false;
}

void UASkill::MulticastUseSkill(const FNetworkSkillInfo& NetworkInfo) {
}

void UASkill::LoadFXAndSounds() {
}

bool UASkill::IsLocallyControlled() const {
    return false;
}

bool UASkill::IsAvailable() {
    return false;
}

void UASkill::InitShockTag(float InElemntalRatio) {
}

void UASkill::InitPierceState(int32 NewPierceAmount) {
}

void UASkill::InitImpactForceState(float DamageRatio) {
}

void UASkill::InitIceTag(float InElemntalRatio) {
}

void UASkill::InitializeProjectilesFromQueue() {
}

void UASkill::InitExplosiveTag(float Radius, UParticleSystem* AreaFX, USoundCue* AreaSound, bool bPermanent, bool bDecal) {
}

void UASkill::InitBurnTag(float BurnRatio) {
}

void UASkill::InitBounceState(int32 NewBounceAmount, float NewBounciness, float NewFriction) {
}

USoundCue* UASkill::GetUseSound_Implementation() {
    return NULL;
}

FVector UASkill::GetStartTrace(int32 Index) const {
    return FVector{};
}

FVector2D UASkill::GetSpread() {
    return FVector2D{};
}

float UASkill::GetSphereRadius(const FNetworkSkillInfo& SKillInfo) const {
    return 0.0f;
}

TArray<FVector2D> UASkill::GetSpawnRotationOffset_Implementation() const {
    return TArray<FVector2D>();
}

TArray<FVector2D> UASkill::GetSpawnLocationOffset_Implementation() const {
    return TArray<FVector2D>();
}

float UASkill::GetSeededRandomRange(int32 Min, int32 Max) {
    return 0.0f;
}

float UASkill::GetRange() const {
    return 0.0f;
}

FVector2D UASkill::GetRandomPointInElipse(FVector2D InSpread) {
    return FVector2D{};
}

FVector2D UASkill::GetRandomPointInCircle(float Radius) {
    return FVector2D{};
}

float UASkill::GetProjectileSpeed_Implementation(const FNetworkSkillInfo& SKillInfo) const {
    return 0.0f;
}

FHitResult UASkill::GetProjectileEndHitResult(const FVector& StartTrace, const FVector& Velocity, float GravityScale, float MaxSimeTime) const {
    return FHitResult{};
}

bool UASkill::GetPlayerOrModSkillRowFromSoftClass(const TSoftClassPtr<UASkill>& SkillClass, FPlayerSkillRow& OutPlayerSkill) const {
    return false;
}

bool UASkill::GetPlayerOrModSkillRowFromRowName(const FName& RowName, FPlayerSkillRow& OutPlayerSkill) const {
    return false;
}

bool UASkill::GetPlayerOrModSkillRowFromClass(const TSubclassOf<UASkill>& SkillClass, FPlayerSkillRow& OutPlayerSkill) const {
    return false;
}

bool UASkill::GetPlayerOrModSkillRow(FPlayerSkillRow& OutPlayerSkill) const {
    return false;
}

FVector UASkill::GetMuzzleLocation(int32 Index) const {
    return FVector{};
}

TArray<int32> UASkill::GetMuzzleIndex_Implementation() const {
    return TArray<int32>();
}

USkeletalMeshComponent* UASkill::GetMuzzleComponent() const {
    return NULL;
}

float UASkill::GetMaxTarget() const {
    return 0.0f;
}

int32 UASkill::GetMaxHitAmount(AAProjectile* Projectile) {
    return 0;
}

UAudioComponent* UASkill::GetLoopingSoundComponent() {
    return NULL;
}

float UASkill::GetImpactForceAmount_Implementation(float ChargeRatio) {
    return 0.0f;
}

TArray<AActor*> UASkill::GetIgnoredActors_Implementation() const {
    return TArray<AActor*>();
}

int32 UASkill::GetHitAmount_Implementation(float ChargeRatio) const {
    return 0;
}

TArray<EGameplayTags> UASkill::GetGameplayTagList() {
    return TArray<EGameplayTags>();
}

FVector UASkill::GetForwardVector_Implementation(int32 Index) const {
    return FVector{};
}

float UASkill::GetDurationDelay_Implementation() {
    return 0.0f;
}

TArray<EDamageTypeGameplay> UASkill::GetDamageTypeGameplay(bool bBase) {
    return TArray<EDamageTypeGameplay>();
}

float UASkill::GetDamageAmount_Implementation(float ChargeRatio) {
    return 0.0f;
}

float UASkill::GetCustomFloatProperties(FName PropertyName) {
    return 0.0f;
}

float UASkill::GetCooldownRatio() {
    return 0.0f;
}

float UASkill::GetConeLength(const FNetworkSkillInfo& SKillInfo) const {
    return 0.0f;
}

float UASkill::GetConeAngle() {
    return 0.0f;
}

AACharacter* UASkill::GetCharacter() const {
    return NULL;
}

float UASkill::GetCalculateFirerate() const {
    return 0.0f;
}

float UASkill::GetCalculateBaseImpactForce() const {
    return 0.0f;
}

float UASkill::GetCalculateBaseDamage() const {
    return 0.0f;
}

FVector UASkill::GetBoxSize(const FNetworkSkillInfo& SKillInfo) const {
    return FVector{};
}

float UASkill::GetBaseImpactForceAmount_Implementation(float ChargeRatio) {
    return 0.0f;
}

TArray<EGameplayTags> UASkill::GetBaseGameplayTagList() {
    return TArray<EGameplayTags>();
}

float UASkill::GetBaseDamageAmount_Implementation(float ChargeRatio) {
    return 0.0f;
}

FVector UASkill::GetAreaStartTrace(const FNetworkSkillInfo& SKillInfo) {
    return FVector{};
}

TSet<EStatus> UASkill::GetAppliedStatus_Implementation(int32 InGameplayTags) {
    return TSet<EStatus>();
}

void UASkill::DelayRetriggerAreaEffect(const FNetworkSkillInfo& SKillInfo, float Delay, float DamageModifier, float RadiusModifier, AAProjectile* Projectile) {
}

bool UASkill::CanUseSkill() {
    return false;
}

bool UASkill::CanCritical(AAProjectile* Projectile) {
    return false;
}

void UASkill::ApplyDamageModifier(UModifier_Damage* NewModifier) {
}

void UASkill::AddSuperTextFeedback() {
}

void UASkill::AddNewTargetTeam(ETeam Team) {
}

void UASkill::AddNewGameplayTag(EGameplayTags Tag) {
}

void UASkill::AddMegaTextFeedback() {
}

void UASkill::AddCustomFloatProperties(FName PropertyName, float AddValue) {
}

void UASkill::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UASkill, TargetAction);
    DOREPLIFETIME(UASkill, RandomSeed);
}


