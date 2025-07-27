#include "LevelStaticMeshActor.h"
#include "LevelStaticMeshComponent.h"

ALevelStaticMeshActor::ALevelStaticMeshActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer.SetDefaultSubobjectClass<ULevelStaticMeshComponent>(TEXT("StaticMeshComponent0"))) {
}


