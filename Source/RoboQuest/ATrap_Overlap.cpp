#include "ATrap_Overlap.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BoxComponent -FallbackName=BoxComponent

AATrap_Overlap::AATrap_Overlap(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
    this->TriggerFirerate = 1.00f;
    this->ExitOverlapDelay = 0.10f;
    this->bIgnoreCapsuleWallCompensation = false;
    this->TriggerBox->SetupAttachment(Root_Activate);
}

void AATrap_Overlap::RefreshOverlapingActors() {
}

void AATrap_Overlap::OnTriggerTrapEffect_Implementation(AActor* InActor) {
}

void AATrap_Overlap::OnTriggerBoxEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void AATrap_Overlap::OnTriggerBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void AATrap_Overlap::OnOverlappingActorDeath(const FRQDamageInfo& DamageInfo) {
}

void AATrap_Overlap::OnDamageableActorBeginOverlap(AActor* InActor) {
}


TArray<AActor*> AATrap_Overlap::GetOverlappingActorsByTeam(ETeam Team) const {
    return TArray<AActor*>();
}

TArray<UPrimitiveComponent*> AATrap_Overlap::GetOverlapComponents_Implementation() const {
    return TArray<UPrimitiveComponent*>();
}


