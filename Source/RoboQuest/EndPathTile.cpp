#include "EndPathTile.h"

FEndPathTile::FEndPathTile() {
    this->Class = NULL;
    this->bIsLastLevel = false;
    this->CompletionTimeCurve = NULL;
    this->PathID = 0;
    this->bGenerateRoof = false;
    this->bCustomBorderTiles = false;
    this->BorderClasses[0] = NULL;
    this->BorderClasses[1] = NULL;
    this->BorderClasses[2] = NULL;
    this->BorderClasses[3] = NULL;
    this->BorderClasses[4] = NULL;
    this->BorderClasses[5] = NULL;
    this->BorderClasses[6] = NULL;
}

