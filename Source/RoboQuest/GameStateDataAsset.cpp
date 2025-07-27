#include "GameStateDataAsset.h"

UGameStateDataAsset::UGameStateDataAsset() {
    this->InteractiveWeaponClass = NULL;
    this->DT_Levels = NULL;
    this->DT_Enemy = NULL;
    this->DT_Ally = NULL;
    this->DT_Difficulty = NULL;
    this->DT_Crystals = NULL;
    this->DT_StoryCapsule = NULL;
    this->DT_HitSurface = NULL;
    this->DT_LocomotionSurface = NULL;
    this->DT_Items = NULL;
    this->DT_BazarItems = NULL;
    this->DT_Weapons = NULL;
    this->DT_Loot = NULL;
    this->DT_AIAttacks = NULL;
    this->DT_PlayerSkills = NULL;
    this->DT_ModSkills = NULL;
    this->DT_EnemySkill = NULL;
    this->DT_AllySkill = NULL;
    this->DT_LevelGeneratorMutator = NULL;
    this->MPC_Borealis = NULL;
    this->RankByStars[0] = 0;
    this->RankByStars[1] = 0;
    this->RankByStars[2] = 0;
    this->RankByStars[3] = 0;
    this->RankByStars[4] = 0;
    this->RankByStars[5] = 0;
    this->StarsByPCPercent[0] = 0;
    this->StarsByPCPercent[1] = 0;
    this->StarsByPCPercent[2] = 0;
    this->StarsByPCPercent[3] = 0;
    this->StarsByPCPercent[4] = 0;
    this->StarsByTimePercent[0] = 0;
    this->StarsByTimePercent[1] = 0;
    this->StarsByTimePercent[2] = 0;
    this->StarsByTimePercent[3] = 0;
    this->StarsByTimePercent[4] = 0;
    this->WeaponCardClass = NULL;
    this->WeaponCardPoolAmount = 3;
    this->EnemyCardClass = NULL;
    this->EnemyCardPoolAmount = 3;
}


