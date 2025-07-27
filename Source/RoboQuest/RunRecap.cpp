#include "RunRecap.h"

FRunRecap::FRunRecap() {
    this->bIsSolo = false;
    this->bIsInfiniteRun = false;
    this->bIsFromSaved = false;
    this->LevelReached = 0;
    this->LevelInfiniteRunReached = 0;
    this->TotalDamageDealt = 0.00f;
    this->BestDamageDealt = 0.00f;
    this->TotalDamageTaken = 0.00f;
    this->EnemiesDestroyed = 0;
    this->PowercellGathered = 0;
    this->WrenchesGathered = 0;
    this->StoryCapsulesGathered = 0;
    this->RunDuration = 0.00f;
    this->TotalRank = ERank::S;
    this->bIsRunFinished = false;
    this->bIsVictory = false;
}

