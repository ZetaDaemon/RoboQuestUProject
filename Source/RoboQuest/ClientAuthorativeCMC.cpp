#include "ClientAuthorativeCMC.h"

UClientAuthorativeCMC::UClientAuthorativeCMC(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bIgnoreClientMovementErrorChecksAndCorrection = true;
    this->bServerAcceptClientAuthoritativePosition = true;
}


