#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=LinearColor -FallbackName=LinearColor
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Matrix -FallbackName=Matrix
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Rotator -FallbackName=Rotator
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BlueprintFunctionLibrary -FallbackName=BlueprintFunctionLibrary
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ECollisionChannel -FallbackName=ECollisionChannel
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ECollisionEnabled -FallbackName=ECollisionEnabled
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ENetworkSmoothingMode -FallbackName=ENetworkSmoothingMode
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=HitResult -FallbackName=HitResult
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=UniqueNetIdRepl -FallbackName=UniqueNetIdRepl
//CROSS-MODULE INCLUDE V2: -ModuleName=InputCore -ObjectName=Key -FallbackName=Key
//CROSS-MODULE INCLUDE V2: -ModuleName=PhysicsCore -ObjectName=EPhysicalSurface -FallbackName=EPhysicalSurface
//CROSS-MODULE INCLUDE V2: -ModuleName=UMG -ObjectName=ESlateVisibility -FallbackName=ESlateVisibility
#include "ArtefactRow.h"
#include "DifficultyRow.h"
#include "EActe.h"
#include "EAction.h"
#include "EBuildType.h"
#include "EConsole.h"
#include "EDirection.h"
#include "EElement.h"
#include "EGameplayTags.h"
#include "EHapticPlatform.h"
#include "EKeywordType.h"
#include "ELevelForSettings.h"
#include "ESocketLocation.h"
#include "EStorePlatform.h"
#include "Keyword.h"
#include "LevelRow.h"
#include "LevelRowHandle.h"
#include "PerkStatModifier.h"
#include "PlayerClassRow.h"
#include "PlayerSkillRow.h"
#include "RQDamageInfo.h"
#include "RQHitResult.h"
#include "Templates/SubclassOf.h"
#include "WeaponRow.h"
#include "WeaponRunRecap.h"
#include "RQBlueprintLibrary.generated.h"

class AATile;
class AActor;
class ACharacter_Player;
class UASkill;
class UATrigger;
class UActorComponent;
class UAnimInstance;
class UAnimSequence;
class UAudioComponent;
class UBoxComponent;
class UButtonSlot;
class UCharacterMovementComponent;
class UChildActorComponent;
class UDataTable;
class UObject;
class USceneComponent;
class USingleton;
class USkeletalMeshComponent;
class USoundClass;
class USoundCue;
class UTexture2D;
class UTrigger_Weapon;
class UWorld;

UCLASS(Blueprintable)
class ROBOQUEST_API URQBlueprintLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    URQBlueprintLibrary();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool WithEditor();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool UseLAN();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString UniqueIdToString(const FUniqueNetIdRepl& NetId);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool TryingToDestroyActor(UObject* WorldContextObject, AActor* Actor);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void TogglePreviousBasecampLevel(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void ToggleNextBasecampLevel(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static void TakeScreenshot(const FString& InFilename, bool bInShowUI);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool SyncLoadWeaponRow(const UObject* WorldContextObject, const FName& RowName, FWeaponRow& OutWeaponRow);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool SyncLoadPlayerSkillRowFromSoftClass(const UObject* WorldContextObject, const TSoftClassPtr<UASkill>& SkillClass, FPlayerSkillRow& OutPlayerSkillRow);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool SyncLoadPlayerSkillRow(const UObject* WorldContextObject, const FName& RowName, FPlayerSkillRow& OutPlayerSkillRow);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool SyncLoadPlayerClassRow(const UObject* WorldContextObject, const FName& RowName, FPlayerClassRow& OutPlayerClassRow);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UClass* SyncLoadObjectClass(const UObject* WorldContextObject, const TSoftClassPtr<UObject>& ClassPtr);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool SyncLoadDifficultyRow(const UObject* WorldContextObject, const FName& RowName, FDifficultyRow& OutDifficultyRow);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool SyncLoadArtefactRow(const UObject* WorldContextObject, const FName& RowName, FArtefactRow& OutArtefactRow);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static TArray<FName> SyncLoadAllDifficultyRowNames(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static TArray<FName> SyncLoadAllActivePlayerClassRowNames(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static void SpawnCustomActorComponent(TSubclassOf<UActorComponent> Class, AActor* Owner, UActorComponent*& SpawnedComponent);
    
    UFUNCTION(BlueprintCallable)
    static void SortArrayOfActorsByName(UPARAM(Ref) TArray<AActor*>& Actors);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static FVector SnapToFloor(const UObject* WorldContextObject, const FVector& WorldLocation, const FVector& BoxExtent, const TArray<AActor*>& ActorsToIgnore, TEnumAsByte<ECollisionChannel> CollisionChannel);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SetSoundClassVolume(UObject* WorldContextObject, USoundClass* SoundClass, float NewVolume);
    
    UFUNCTION(BlueprintCallable)
    static void SetSoundAttenuationShapeExtents(UAudioComponent* AudioComponent, const FVector& ShapeExtents);
    
    UFUNCTION(BlueprintCallable)
    static void SetNetworkinkSmoothMode(UCharacterMovementComponent* InCharacterMovement, ENetworkSmoothingMode NewMode);
    
    UFUNCTION(BlueprintCallable)
    static bool SaveStringTextToFile(const FString& SaveDirectory, const FString& JoyfulFileName, const FString& SaveText, bool AllowOverWriting, bool AllowAppend);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float RoundFloatToDecimal(float InFloat, int32 DecimalNumber);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void PrintLogRyseUp(UObject* WorldContextObject, const FString& LogText);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UAudioComponent* PlaySoundVibrationAtLocation(const UObject* WorldContextObject, USoundCue* SoudRef, FVector Location, FRotator Rotator, float Intensity, bool bAutoDestroy);
    
    UFUNCTION(BlueprintCallable)
    static FString PasteMessageFromClipboard();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FText ParseTextValues(ACharacter_Player* PlayerRef, const FText& BaseText, const TMap<FName, float>& Values, const FString& Prefix, const FString& Suffix);
    
    UFUNCTION(BlueprintCallable)
    static void MarkComponentsRenderStateDirty(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsTestOrShippingBuild();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsSteam();
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsSoloGame(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsSavedRun(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static bool IsPreLoadingScreenClosed();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsPlaystationStore();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsPlatformXSX();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsPlatformXboxOne();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsPlatformPS5();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsPlatformPS4();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsPlatformConsole();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsMicrosoftStore();
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsLoggedInXboxLive(UObject* WorldContextObject, int32 PlayerNum);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsInLevelList(const TArray<FLevelRowHandle>& LevelList, const FName& Name);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsInEditor(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsGOG();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsGamescomBuild();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsGamePadConnected();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsEGS();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsDamageable(AActor* TargetActor);
    
    UFUNCTION(BlueprintCallable)
    static bool IsBlueprintClass(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsAzertyKeyboard();
    
    UFUNCTION(BlueprintPure)
    static FString Int64ToString(int64 Value);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool HaveSaveRunSystem();
    
    UFUNCTION(BlueprintCallable)
    static bool HaveEndResult(const TArray<FRQHitResult>& InResults);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetYawDifference(const FVector& ForwardVector, const FVector& CurrentLocation, const FVector& TargetLocation);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static uint8 GetWorkersEncounterID();
    
    UFUNCTION(BlueprintCallable)
    static FPlayerSkillRow GetWeaponSkillRow(FWeaponRow BaseRow, UDataTable* DataPlayerSkillRef, EAction TargetAction);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static uint8 GetWallTurretsEncounterID();
    
    UFUNCTION(BlueprintCallable)
    static float GetVectorDistance(FVector Start, FVector End);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector GetTransformedFOVPosition(FMatrix RenderMat, FVector PositionInLocalSpace);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString GetTitleMapName();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FText GetTimeAsText(float Seconds, bool bWithMilliseconds);
    
    UFUNCTION(BlueprintCallable)
    static TArray<USceneComponent*> GetSubcomponentsByClass(USceneComponent* PrimitiveComponent, TSubclassOf<USceneComponent> Class, bool bIncludeAllDescendent);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static EStorePlatform GetStorePlatform();
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static float GetSlotMontageLocalWeight(const UObject* WorldContextObject, UAnimInstance* AnimInstanceRef, const FName& SlotName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static float GetSlotMontageGlobalWeight(const UObject* WorldContextObject, UAnimInstance* AnimInstanceRef, const FName& SlotName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static USingleton* GetSingleton();
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static AActor* GetRicochetTarget(UObject* WorldContextObject, const FVector& SourceLocation, int32 TargetTeams, TArray<AActor*> IgnoredActors);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetRenderResolution(int32& OutResX, int32& OutResY);
    
    UFUNCTION(BlueprintCallable)
    static FRQHitResult GetRaycastEndNoHitResult(UWorld* World, const FVector& StartTrace, const FVector& ForwardVector, float RaycastLength);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector2D GetRandomPointInCircle(float Radius);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector GetPredictedLocation(const FVector& BaseLocation, const FVector& Velocity, float InTime, bool bCalculateZVelocity);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString GetPlatformName();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static EConsole GetPlatformConsole();
    
    UFUNCTION(BlueprintCallable)
    static float GetPerkModifiedValue(float BaseValue, FPerkStatModifier PerkStatModifier);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static AATile* GetParentTileFromActor(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString GetOSVersion();
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static FString GetMostRecentDmpFilePath(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static EDirection GetMirrorDirection(EDirection Direction);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static TArray<UTexture2D*> GetLoadingTexturesFromLevelRow(const UObject* WorldContextObject, const FLevelRow& LevelRow);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static ELevelForSettings GetLevelEnumByName(UObject* WorldContextObject, const FString& GameLevelName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FName GetKeyName(FKey Key);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetIsFadingOut(UAudioComponent* AudioComponent);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString GetInfiniteRunMapName();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static uint8 GetHoleSpawnersEncounterID();
    
    UFUNCTION(BlueprintCallable)
    static EDirection GetHitDirection(const FVector& StartLocation, const FVector& BodyLocation, const FVector& ForwardVector);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static EHapticPlatform GetHapticPlatform();
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static FVector GetGroundLocation(UObject* WorldContextObject, const FVector& Location);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString GetGPUBrandName();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static EGameplayTags GetGameplayTagByElement(EElement Element);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FKey GetGamepadBackKey();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FKey GetGamepadAcceptKey();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString GetGameName();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString GetGameMapName();
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static FText GetFormattedTextWithCustomKeywordsFromString(const UObject* WorldContextObject, const FString& BaseString, bool bRichText, const TArray<FKeyword>& CustomKeywords);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static FText GetFormattedTextWithCustomKeywords(const UObject* WorldContextObject, const FText& BaseText, bool bRichText, const TArray<FKeyword>& CustomKeywords);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static FText GetFormattedText(const UObject* WorldContextObject, const FText& BaseText, bool bRichText);
    
    UFUNCTION(BlueprintCallable)
    static FText GetFormattedSkillDescription(ACharacter_Player* PlayerRef, const FPlayerSkillRow& PlayerSkillRow, const TMap<FName, float>& ClassValues, const FText& passiveName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetElementalId(EElement Element);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FLinearColor GetElementalColor(EElement Element);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetDisplayRange(float InRange);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FName GetDataRowName(const FString& className);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString GetCPUVendorName();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetCPUCores();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString GetCPUChipset();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString GetCPUBrandName();
    
    UFUNCTION(BlueprintCallable)
    static float GetConeWidth(float Angle, float Length);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UObject* GetClassDefaultObject(UClass* Class);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static EBuildType GetBuildType();
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static AActor* GetBouncingHomingTarget(UObject* WorldContextObject, FVector StartLocation, FVector ForwardVector);
    
    UFUNCTION(BlueprintCallable)
    static uint8 GetBossCountFromPreviousActs(const UDataTable* DT_Acts, EActe Act);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FWeaponRunRecap GetBaseWeaponRunRecap(FWeaponRow BaseRow, FName RowName, UDataTable* DataPlayerSkillRef);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString GetBasecampMapOptions();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString GetBasecampMapName();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetAnimSequenceLength(UAnimSequence* AnimSequence);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FName GetAISocketName(ESocketLocation SocketLocation);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetAimDifference(float CurAim, float WantedAIM);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static EActe GetActFromLevelRow(const FLevelRow& LevelRow);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FKeyword GenerateKeyword(FName KeywordSearch, const FText& KeywordDisplay, EKeywordType Type, FName TargetFormat, bool bLowercase);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GenerateEnemySpawnParametersBitmask(bool bCanLoot, bool bAlwaysShielded, bool bElite, bool bIsBoss, bool bIsBig, bool bNoXP, bool bHeadbonkBubble, bool bEyeProtection, bool bTurretEmpower, bool bExplodeOnDeath);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void GDK_PromptAccountPickerAndRestartIfNeeded(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void GDK_PromptAccountPicker(UObject* WorldContextObject, bool& bIsSameUser);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool FindCorrectTeleportLocation(AActor* Actor, const FVector& InTeleportLocation, const FRotator& TeleportRotation, float Offset, int32 TryCount, float ErrorRadius, FVector& OutTeleportLocation);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static TArray<FRQHitResult> FindBySphere(UObject* WorldContextObject, const FVector& StartTrace, float Radius, int32 TargetTeams, TArray<AActor*> IgnoredActors, int32 MaxResult, bool bShowDebugTrace, AActor* Instigator);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static TArray<FRQHitResult> FindByRaycast(UObject* WorldContextObject, const FVector& StartTrace, FVector ForwardVector, float RaycastLength, int32 TargetTeams, TArray<AActor*> IgnoredActors, int32 MaxResult, int32 BounceAmount, int32 RicochetAmount, bool bShowDebugTrace, AActor* Instigator, bool bCalculateBouncingHoming);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static TArray<FRQHitResult> FindByCone(UObject* WorldContextObject, const FVector& StartTrace, const FVector& ConeStartTrace, const FVector& ForwardVector, float ConeAngle, float ConeLength, int32 TargetTeams, TArray<AActor*> IgnoredActors, int32 MaxResult, bool bShowDebugTrace, AActor* Instigator, bool bAimAssist);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static TArray<FRQHitResult> FindByBox(UObject* WorldContextObject, const FVector& StartTrace, const FVector& ForwardVector, float BoxLength, float BoxWidth, float BoxHeight, int32 TargetTeams, TArray<AActor*> IgnoredActors, int32 MaxResult, bool bShowDebugTrace, AActor* Instigator);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void ExecuteGraphicConsoleCommand(const UObject* WorldContextObject, const FString& Command, float Value);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void ExecuteConsoleCommandWithPrint(const UObject* WorldContextObject, const FString& Command);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void DumpReplicatedActorStates(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static void CopyMessageToClipboard(const FString& Text);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void ClosePreLoadingScreen(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float ClampFloatRotation(float InFloat);
    
    UFUNCTION(BlueprintCallable)
    static bool CheckFlagToBitmask(uint8 NewFlag, int32 TargetBitmask);
    
    UFUNCTION(BlueprintCallable)
    static void ChangeCollisionOnPhysicsBody(USkeletalMeshComponent* SkeletalMesh, FName BoneName, TEnumAsByte<ECollisionEnabled::Type> CollisionType);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void CancelPendingJoinSession(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float CalculateFOVforResolution(float baseFOV);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void BlueprintRandomizeMesh(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString ArrayOfFNameToString(const TArray<FName>& ArrayFName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool AreBoxesIntersecting(UBoxComponent* Box1, UBoxComponent* Box2);
    
    UFUNCTION(BlueprintCallable)
    static void AppendMap(UPARAM(Ref) TMap<FString, float>& TargetMap, const TMap<FString, float>& SourceMap);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool AllowIngameRandomization();
    
    UFUNCTION(BlueprintCallable)
    static UTrigger_Weapon* AddTriggerWeapon(ACharacter_Player* OwningPlayer);
    
    UFUNCTION(BlueprintCallable)
    static UATrigger* AddTrigger();
    
    UFUNCTION(BlueprintCallable)
    static uint8 AddFlagToBitmask(uint8 NewFlag, uint8 TargetBitmask);
    
    UFUNCTION(BlueprintCallable)
    static void ActivateSpecificJumpads(const TArray<UChildActorComponent*>& JumpadComponents, bool bActivate);
    
    UFUNCTION(BlueprintCallable)
    static void ActivateSpecialWave(AActor* SpecialInterior, int32 WaveID);
    
};

