#include "GeneratorRunSaveGame.h"

FGeneratorRunSaveGame::FGeneratorRunSaveGame() {
    this->bInfiniteRun = false;
    this->LastAct = EActe::Acte1;
    this->RandomSeed = 0;
    this->GameTime = 0.00f;
    this->CurrentInfiniteRunLevelAmount = 0;
}

