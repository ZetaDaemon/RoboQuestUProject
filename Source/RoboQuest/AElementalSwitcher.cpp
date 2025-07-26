#include "AElementalSwitcher.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
#include "Net/UnrealNetwork.h"

AAElementalSwitcher::AAElementalSwitcher(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    this->Root = (USceneComponent*)RootComponent;
    this->CurrentElement = EElement::LastIndex;
    this->bCanSwitchElement = true;
    this->GameStateRef = NULL;
}

void AAElementalSwitcher::RepNotify_CurrentElement() {
}

void AAElementalSwitcher::OnApplyNewElement_Implementation(EElement Element, bool bInstant) {
}

void AAElementalSwitcher::InitFirstElement(EElement InElement) {
}

AAGameState* AAElementalSwitcher::GetGameStateRef() const {
    return NULL;
}

void AAElementalSwitcher::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AAElementalSwitcher, CurrentElement);
}


