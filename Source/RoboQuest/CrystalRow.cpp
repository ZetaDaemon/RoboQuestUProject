#include "CrystalRow.h"

FCrystalRow::FCrystalRow() {
    this->Order = 0;
    this->MeshOffsetZ = 0.00f;
    this->FXCrystalID = 0;
    this->Pipe = NULL;
    this->PipeIcon = NULL;
    this->bIsAutoValidated = false;
    this->bIsDeactivated = false;
}

