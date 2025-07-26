#include "WeaponRow.h"

FWeaponRow::FWeaponRow() {
    this->LootCategory = EWeaponCategory::Assault;
    this->AmmoInClip = 0.00f;
    this->ReloadDuration = 0.00f;
    this->bCanShotWhileScopped = false;
    this->LootLevel = 0;
    this->RecoilRecoverySpeed = 0.00f;
    this->RecoilRecoveryMultiplierPerSecond = 0.00f;
    this->MaxRecoilRecoverySpeed = 0.00f;
    this->SpreadRecoverySpeed = 0.00f;
    this->SpreadIncreaseCurve = 0.00f;
    this->HandPoseType = EAnimPose::T00;
    this->Duration = 0.00f;
    this->RegenDuration = 0.00f;
    this->bContinueLoopingSoundWhileShoot = false;
    this->WarmupFirerateModifier = NULL;
    this->UpSpeed = 0.00f;
    this->DownSpeed = 0.00f;
    this->LoadedMesh = NULL;
    this->OnomatopoeiaGeneration = EWeaponGeneration::G1;
    this->FeedbackMuzzleScale = 0.00f;
    this->bLimitedClip = false;
    this->bScope = false;
    this->bWarmup = false;
    this->bCooling = false;
    this->bTemperature = false;
    this->bSpecificHandPose = false;
    this->bLootable = false;
    this->bLootableInShippingBuild = false;
    this->bDeactivateMagnetism = false;
    this->bIsInCompendium = false;
    this->CompendiumProgressionMultiplier = 0;
    this->Generation = EWeaponGeneration::G1;
    this->bExcludeForSuperbot = false;
}

