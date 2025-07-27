#include "RQBlueprintLibrary.h"
#include "Templates/SubclassOf.h"

URQBlueprintLibrary::URQBlueprintLibrary() {
}

bool URQBlueprintLibrary::WithEditor() {
    return false;
}

bool URQBlueprintLibrary::UseLAN() {
    return false;
}

FString URQBlueprintLibrary::UniqueIdToString(const FUniqueNetIdRepl& NetId) {
    return TEXT("");
}

bool URQBlueprintLibrary::TryingToDestroyActor(UObject* WorldContextObject, AActor* Actor) {
    return false;
}

void URQBlueprintLibrary::TogglePreviousBasecampLevel(UObject* WorldContextObject) {
}

void URQBlueprintLibrary::ToggleNextBasecampLevel(UObject* WorldContextObject) {
}

void URQBlueprintLibrary::TakeScreenshot(const FString& InFilename, bool bInShowUI) {
}

bool URQBlueprintLibrary::SyncLoadWeaponRow(const UObject* WorldContextObject, const FName& RowName, FWeaponRow& OutWeaponRow) {
    return false;
}

bool URQBlueprintLibrary::SyncLoadPlayerSkillRowFromSoftClass(const UObject* WorldContextObject, const TSoftClassPtr<UASkill>& SkillClass, FPlayerSkillRow& OutPlayerSkillRow) {
    return false;
}

bool URQBlueprintLibrary::SyncLoadPlayerSkillRow(const UObject* WorldContextObject, const FName& RowName, FPlayerSkillRow& OutPlayerSkillRow) {
    return false;
}

bool URQBlueprintLibrary::SyncLoadPlayerClassRow(const UObject* WorldContextObject, const FName& RowName, FPlayerClassRow& OutPlayerClassRow) {
    return false;
}

UClass* URQBlueprintLibrary::SyncLoadObjectClass(const UObject* WorldContextObject, const TSoftClassPtr<UObject>& ClassPtr) {
    return NULL;
}

bool URQBlueprintLibrary::SyncLoadDifficultyRow(const UObject* WorldContextObject, const FName& RowName, FDifficultyRow& OutDifficultyRow) {
    return false;
}

bool URQBlueprintLibrary::SyncLoadArtefactRow(const UObject* WorldContextObject, const FName& RowName, FArtefactRow& OutArtefactRow) {
    return false;
}

TArray<FName> URQBlueprintLibrary::SyncLoadAllDifficultyRowNames(const UObject* WorldContextObject) {
    return TArray<FName>();
}

TArray<FName> URQBlueprintLibrary::SyncLoadAllActivePlayerClassRowNames(const UObject* WorldContextObject) {
    return TArray<FName>();
}

void URQBlueprintLibrary::SpawnCustomActorComponent(TSubclassOf<UActorComponent> Class, AActor* Owner, UActorComponent*& SpawnedComponent) {
}

void URQBlueprintLibrary::SortArrayOfActorsByName(TArray<AActor*>& Actors) {
}

FVector URQBlueprintLibrary::SnapToFloor(const UObject* WorldContextObject, const FVector& WorldLocation, const FVector& BoxExtent, const TArray<AActor*>& ActorsToIgnore, TEnumAsByte<ECollisionChannel> CollisionChannel) {
    return FVector{};
}


void URQBlueprintLibrary::SetSoundClassVolume(UObject* WorldContextObject, USoundClass* SoundClass, float NewVolume) {
}

void URQBlueprintLibrary::SetSoundAttenuationShapeExtents(UAudioComponent* AudioComponent, const FVector& ShapeExtents) {
}

void URQBlueprintLibrary::SetNetworkinkSmoothMode(UCharacterMovementComponent* InCharacterMovement, ENetworkSmoothingMode NewMode) {
}

bool URQBlueprintLibrary::SaveStringTextToFile(const FString& SaveDirectory, const FString& JoyfulFileName, const FString& SaveText, bool AllowOverWriting, bool AllowAppend) {
    return false;
}

float URQBlueprintLibrary::RoundFloatToDecimal(float InFloat, int32 DecimalNumber) {
    return 0.0f;
}

void URQBlueprintLibrary::PrintLogRyseUp(UObject* WorldContextObject, const FString& LogText) {
}

UAudioComponent* URQBlueprintLibrary::PlaySoundVibrationAtLocation(const UObject* WorldContextObject, USoundCue* SoudRef, FVector Location, FRotator Rotator, float Intensity, bool bAutoDestroy) {
    return NULL;
}

FString URQBlueprintLibrary::PasteMessageFromClipboard() {
    return TEXT("");
}

FText URQBlueprintLibrary::ParseTextValues(ACharacter_Player* PlayerRef, const FText& BaseText, const TMap<FName, float>& Values, const FString& Prefix, const FString& Suffix) {
    return FText::GetEmpty();
}

void URQBlueprintLibrary::MarkComponentsRenderStateDirty(AActor* Actor) {
}

bool URQBlueprintLibrary::IsTestOrShippingBuild() {
    return false;
}

bool URQBlueprintLibrary::IsSteam() {
    return false;
}

bool URQBlueprintLibrary::IsSoloGame(const UObject* WorldContextObject) {
    return false;
}

bool URQBlueprintLibrary::IsSavedRun(const UObject* WorldContextObject) {
    return false;
}

bool URQBlueprintLibrary::IsPreLoadingScreenClosed() {
    return false;
}

bool URQBlueprintLibrary::IsPlaystationStore() {
    return false;
}

bool URQBlueprintLibrary::IsPlatformXSX() {
    return false;
}

bool URQBlueprintLibrary::IsPlatformXboxOne() {
    return false;
}

bool URQBlueprintLibrary::IsPlatformPS5() {
    return false;
}

bool URQBlueprintLibrary::IsPlatformPS4() {
    return false;
}

bool URQBlueprintLibrary::IsPlatformConsole() {
    return false;
}

bool URQBlueprintLibrary::IsMicrosoftStore() {
    return false;
}

bool URQBlueprintLibrary::IsLoggedInXboxLive(UObject* WorldContextObject, int32 PlayerNum) {
    return false;
}

bool URQBlueprintLibrary::IsInLevelList(const TArray<FLevelRowHandle>& LevelList, const FName& Name) {
    return false;
}

bool URQBlueprintLibrary::IsInEditor(const UObject* WorldContextObject) {
    return false;
}

bool URQBlueprintLibrary::IsGOG() {
    return false;
}

bool URQBlueprintLibrary::IsGamescomBuild() {
    return false;
}

bool URQBlueprintLibrary::IsGamePadConnected() {
    return false;
}

bool URQBlueprintLibrary::IsEGS() {
    return false;
}

bool URQBlueprintLibrary::IsDamageable(AActor* TargetActor) {
    return false;
}

bool URQBlueprintLibrary::IsBlueprintClass(AActor* Actor) {
    return false;
}

bool URQBlueprintLibrary::IsAzertyKeyboard() {
    return false;
}

FString URQBlueprintLibrary::Int64ToString(int64 Value) {
    return TEXT("");
}

bool URQBlueprintLibrary::HaveSaveRunSystem() {
    return false;
}

bool URQBlueprintLibrary::HaveEndResult(const TArray<FRQHitResult>& InResults) {
    return false;
}

float URQBlueprintLibrary::GetYawDifference(const FVector& ForwardVector, const FVector& CurrentLocation, const FVector& TargetLocation) {
    return 0.0f;
}

uint8 URQBlueprintLibrary::GetWorkersEncounterID() {
    return 0;
}

FPlayerSkillRow URQBlueprintLibrary::GetWeaponSkillRow(FWeaponRow BaseRow, UDataTable* DataPlayerSkillRef, EAction TargetAction) {
    return FPlayerSkillRow{};
}

uint8 URQBlueprintLibrary::GetWallTurretsEncounterID() {
    return 0;
}

float URQBlueprintLibrary::GetVectorDistance(FVector Start, FVector End) {
    return 0.0f;
}

FVector URQBlueprintLibrary::GetTransformedFOVPosition(FMatrix RenderMat, FVector PositionInLocalSpace) {
    return FVector{};
}

FString URQBlueprintLibrary::GetTitleMapName() {
    return TEXT("");
}

FText URQBlueprintLibrary::GetTimeAsText(float Seconds, bool bWithMilliseconds) {
    return FText::GetEmpty();
}

TArray<USceneComponent*> URQBlueprintLibrary::GetSubcomponentsByClass(USceneComponent* PrimitiveComponent, TSubclassOf<USceneComponent> Class, bool bIncludeAllDescendent) {
    return TArray<USceneComponent*>();
}

EStorePlatform URQBlueprintLibrary::GetStorePlatform() {
    return EStorePlatform::Steam;
}

float URQBlueprintLibrary::GetSlotMontageLocalWeight(const UObject* WorldContextObject, UAnimInstance* AnimInstanceRef, const FName& SlotName) {
    return 0.0f;
}

float URQBlueprintLibrary::GetSlotMontageGlobalWeight(const UObject* WorldContextObject, UAnimInstance* AnimInstanceRef, const FName& SlotName) {
    return 0.0f;
}

USingleton* URQBlueprintLibrary::GetSingleton() {
    return NULL;
}

AActor* URQBlueprintLibrary::GetRicochetTarget(UObject* WorldContextObject, const FVector& SourceLocation, int32 TargetTeams, TArray<AActor*> IgnoredActors) {
    return NULL;
}

void URQBlueprintLibrary::GetRenderResolution(int32& OutResX, int32& OutResY) {
}

FRQHitResult URQBlueprintLibrary::GetRaycastEndNoHitResult(UWorld* World, const FVector& StartTrace, const FVector& ForwardVector, float RaycastLength) {
    return FRQHitResult{};
}

FVector2D URQBlueprintLibrary::GetRandomPointInCircle(float Radius) {
    return FVector2D{};
}

FVector URQBlueprintLibrary::GetPredictedLocation(const FVector& BaseLocation, const FVector& Velocity, float InTime, bool bCalculateZVelocity) {
    return FVector{};
}

FString URQBlueprintLibrary::GetPlatformName() {
    return TEXT("");
}

EConsole URQBlueprintLibrary::GetPlatformConsole() {
    return EConsole::XBoxOneS;
}

float URQBlueprintLibrary::GetPerkModifiedValue(float BaseValue, FPerkStatModifier PerkStatModifier) {
    return 0.0f;
}

AATile* URQBlueprintLibrary::GetParentTileFromActor(AActor* Actor) {
    return NULL;
}

FString URQBlueprintLibrary::GetOSVersion() {
    return TEXT("");
}

FString URQBlueprintLibrary::GetMostRecentDmpFilePath(const UObject* WorldContextObject) {
    return TEXT("");
}

EDirection URQBlueprintLibrary::GetMirrorDirection(EDirection Direction) {
    return EDirection::Up;
}

TArray<UTexture2D*> URQBlueprintLibrary::GetLoadingTexturesFromLevelRow(const UObject* WorldContextObject, const FLevelRow& LevelRow) {
    return TArray<UTexture2D*>();
}

ELevelForSettings URQBlueprintLibrary::GetLevelEnumByName(UObject* WorldContextObject, const FString& GameLevelName) {
    return ELevelForSettings::Title;
}

FName URQBlueprintLibrary::GetKeyName(FKey Key) {
    return NAME_None;
}

bool URQBlueprintLibrary::GetIsFadingOut(UAudioComponent* AudioComponent) {
    return false;
}

FString URQBlueprintLibrary::GetInfiniteRunMapName() {
    return TEXT("");
}

uint8 URQBlueprintLibrary::GetHoleSpawnersEncounterID() {
    return 0;
}

EDirection URQBlueprintLibrary::GetHitDirection(const FVector& StartLocation, const FVector& BodyLocation, const FVector& ForwardVector) {
    return EDirection::Up;
}

EHapticPlatform URQBlueprintLibrary::GetHapticPlatform() {
    return EHapticPlatform::PC;
}

FVector URQBlueprintLibrary::GetGroundLocation(UObject* WorldContextObject, const FVector& Location) {
    return FVector{};
}

FString URQBlueprintLibrary::GetGPUBrandName() {
    return TEXT("");
}

EGameplayTags URQBlueprintLibrary::GetGameplayTagByElement(EElement Element) {
    return EGameplayTags::Explosive;
}

FKey URQBlueprintLibrary::GetGamepadBackKey() {
    return FKey{};
}

FKey URQBlueprintLibrary::GetGamepadAcceptKey() {
    return FKey{};
}

FString URQBlueprintLibrary::GetGameName() {
    return TEXT("");
}

FString URQBlueprintLibrary::GetGameMapName() {
    return TEXT("");
}

FText URQBlueprintLibrary::GetFormattedTextWithCustomKeywordsFromString(const UObject* WorldContextObject, const FString& BaseString, bool bRichText, const TArray<FKeyword>& CustomKeywords) {
    return FText::GetEmpty();
}

FText URQBlueprintLibrary::GetFormattedTextWithCustomKeywords(const UObject* WorldContextObject, const FText& BaseText, bool bRichText, const TArray<FKeyword>& CustomKeywords) {
    return FText::GetEmpty();
}

FText URQBlueprintLibrary::GetFormattedText(const UObject* WorldContextObject, const FText& BaseText, bool bRichText) {
    return FText::GetEmpty();
}

FText URQBlueprintLibrary::GetFormattedSkillDescription(ACharacter_Player* PlayerRef, const FPlayerSkillRow& PlayerSkillRow, const TMap<FName, float>& ClassValues, const FText& passiveName) {
    return FText::GetEmpty();
}

float URQBlueprintLibrary::GetElementalId(EElement Element) {
    return 0.0f;
}

FLinearColor URQBlueprintLibrary::GetElementalColor(EElement Element) {
    return FLinearColor{};
}

float URQBlueprintLibrary::GetDisplayRange(float InRange) {
    return 0.0f;
}

FName URQBlueprintLibrary::GetDataRowName(const FString& className) {
    return NAME_None;
}

FString URQBlueprintLibrary::GetCPUVendorName() {
    return TEXT("");
}

int32 URQBlueprintLibrary::GetCPUCores() {
    return 0;
}

FString URQBlueprintLibrary::GetCPUChipset() {
    return TEXT("");
}

FString URQBlueprintLibrary::GetCPUBrandName() {
    return TEXT("");
}

float URQBlueprintLibrary::GetConeWidth(float Angle, float Length) {
    return 0.0f;
}

UObject* URQBlueprintLibrary::GetClassDefaultObject(UClass* Class) {
    return NULL;
}

EBuildType URQBlueprintLibrary::GetBuildType() {
    return EBuildType::Base;
}

AActor* URQBlueprintLibrary::GetBouncingHomingTarget(UObject* WorldContextObject, FVector StartLocation, FVector ForwardVector) {
    return NULL;
}

uint8 URQBlueprintLibrary::GetBossCountFromPreviousActs(const UDataTable* DT_Acts, EActe Act) {
    return 0;
}

FWeaponRunRecap URQBlueprintLibrary::GetBaseWeaponRunRecap(FWeaponRow BaseRow, FName RowName, UDataTable* DataPlayerSkillRef) {
    return FWeaponRunRecap{};
}

FString URQBlueprintLibrary::GetBasecampMapOptions() {
    return TEXT("");
}

FString URQBlueprintLibrary::GetBasecampMapName() {
    return TEXT("");
}

float URQBlueprintLibrary::GetAnimSequenceLength(UAnimSequence* AnimSequence) {
    return 0.0f;
}

FName URQBlueprintLibrary::GetAISocketName(ESocketLocation SocketLocation) {
    return NAME_None;
}

float URQBlueprintLibrary::GetAimDifference(float CurAim, float WantedAIM) {
    return 0.0f;
}

EActe URQBlueprintLibrary::GetActFromLevelRow(const FLevelRow& LevelRow) {
    return EActe::Acte1;
}

FKeyword URQBlueprintLibrary::GenerateKeyword(FName KeywordSearch, const FText& KeywordDisplay, EKeywordType Type, FName TargetFormat, bool bLowercase) {
    return FKeyword{};
}

int32 URQBlueprintLibrary::GenerateEnemySpawnParametersBitmask(bool bCanLoot, bool bAlwaysShielded, bool bElite, bool bIsBoss, bool bIsBig, bool bNoXP, bool bHeadbonkBubble, bool bEyeProtection, bool bTurretEmpower, bool bExplodeOnDeath) {
    return 0;
}

void URQBlueprintLibrary::GDK_PromptAccountPickerAndRestartIfNeeded(UObject* WorldContextObject) {
}

void URQBlueprintLibrary::GDK_PromptAccountPicker(UObject* WorldContextObject, bool& bIsSameUser) {
}

bool URQBlueprintLibrary::FindCorrectTeleportLocation(AActor* Actor, const FVector& InTeleportLocation, const FRotator& TeleportRotation, float Offset, int32 TryCount, float ErrorRadius, FVector& OutTeleportLocation) {
    return false;
}

TArray<FRQHitResult> URQBlueprintLibrary::FindBySphere(UObject* WorldContextObject, const FVector& StartTrace, float Radius, int32 TargetTeams, TArray<AActor*> IgnoredActors, int32 MaxResult, bool bShowDebugTrace, AActor* Instigator) {
    return TArray<FRQHitResult>();
}

TArray<FRQHitResult> URQBlueprintLibrary::FindByRaycast(UObject* WorldContextObject, const FVector& StartTrace, FVector ForwardVector, float RaycastLength, int32 TargetTeams, TArray<AActor*> IgnoredActors, int32 MaxResult, int32 BounceAmount, int32 RicochetAmount, bool bShowDebugTrace, AActor* Instigator, bool bCalculateBouncingHoming) {
    return TArray<FRQHitResult>();
}

TArray<FRQHitResult> URQBlueprintLibrary::FindByCone(UObject* WorldContextObject, const FVector& StartTrace, const FVector& ConeStartTrace, const FVector& ForwardVector, float ConeAngle, float ConeLength, int32 TargetTeams, TArray<AActor*> IgnoredActors, int32 MaxResult, bool bShowDebugTrace, AActor* Instigator, bool bAimAssist) {
    return TArray<FRQHitResult>();
}

TArray<FRQHitResult> URQBlueprintLibrary::FindByBox(UObject* WorldContextObject, const FVector& StartTrace, const FVector& ForwardVector, float BoxLength, float BoxWidth, float BoxHeight, int32 TargetTeams, TArray<AActor*> IgnoredActors, int32 MaxResult, bool bShowDebugTrace, AActor* Instigator) {
    return TArray<FRQHitResult>();
}

void URQBlueprintLibrary::ExecuteGraphicConsoleCommand(const UObject* WorldContextObject, const FString& Command, float Value) {
}

void URQBlueprintLibrary::ExecuteConsoleCommandWithPrint(const UObject* WorldContextObject, const FString& Command) {
}

void URQBlueprintLibrary::DumpReplicatedActorStates(const UObject* WorldContextObject) {
}

void URQBlueprintLibrary::CopyMessageToClipboard(const FString& Text) {
}

void URQBlueprintLibrary::ClosePreLoadingScreen(const UObject* WorldContextObject) {
}

float URQBlueprintLibrary::ClampFloatRotation(float InFloat) {
    return 0.0f;
}

bool URQBlueprintLibrary::CheckFlagToBitmask(uint8 NewFlag, int32 TargetBitmask) {
    return false;
}

void URQBlueprintLibrary::ChangeCollisionOnPhysicsBody(USkeletalMeshComponent* SkeletalMesh, FName BoneName, TEnumAsByte<ECollisionEnabled::Type> CollisionType) {
}

void URQBlueprintLibrary::CancelPendingJoinSession(UObject* WorldContextObject) {
}

float URQBlueprintLibrary::CalculateFOVforResolution(float baseFOV) {
    return 0.0f;
}

void URQBlueprintLibrary::BlueprintRandomizeMesh(UObject* WorldContextObject) {
}

FString URQBlueprintLibrary::ArrayOfFNameToString(const TArray<FName>& ArrayFName) {
    return TEXT("");
}

bool URQBlueprintLibrary::AreBoxesIntersecting(UBoxComponent* Box1, UBoxComponent* Box2) {
    return false;
}

void URQBlueprintLibrary::AppendMap(TMap<FString, float>& TargetMap, const TMap<FString, float>& SourceMap) {
}

bool URQBlueprintLibrary::AllowIngameRandomization() {
    return false;
}

UTrigger_Weapon* URQBlueprintLibrary::AddTriggerWeapon(ACharacter_Player* OwningPlayer) {
    return NULL;
}

UATrigger* URQBlueprintLibrary::AddTrigger() {
    return NULL;
}

uint8 URQBlueprintLibrary::AddFlagToBitmask(uint8 NewFlag, uint8 TargetBitmask) {
    return 0;
}

void URQBlueprintLibrary::ActivateSpecificJumpads(const TArray<UChildActorComponent*>& JumpadComponents, bool bActivate) {
}

void URQBlueprintLibrary::ActivateSpecialWave(AActor* SpecialInterior, int32 WaveID) {
}


