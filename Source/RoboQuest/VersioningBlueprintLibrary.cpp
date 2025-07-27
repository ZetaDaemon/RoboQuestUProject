#include "VersioningBlueprintLibrary.h"

UVersioningBlueprintLibrary::UVersioningBlueprintLibrary() {
}

FString UVersioningBlueprintLibrary::GetVersion_NoRevision() {
    return TEXT("");
}

FString UVersioningBlueprintLibrary::GetVersion() {
    return TEXT("");
}

int32 UVersioningBlueprintLibrary::GetSVNRevision() {
    return 0;
}

int32 UVersioningBlueprintLibrary::GetPatchVersion() {
    return 0;
}

int32 UVersioningBlueprintLibrary::GetMinorVersion() {
    return 0;
}

int32 UVersioningBlueprintLibrary::GetMajorVersion() {
    return 0;
}

int32 UVersioningBlueprintLibrary::GetGameID() {
    return 0;
}

FString UVersioningBlueprintLibrary::GetBuildID() {
    return TEXT("");
}


