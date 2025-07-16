#pragma once
#include "CoreMinimal.h"
#include "EBPOnlineServerConnectionStatusGDK.generated.h"

UENUM(BlueprintType)
enum class EBPOnlineServerConnectionStatusGDK : uint8 {
    Normal,
    NotConnected,
    Connected,
    ConnectionDropped,
    NoNetworkConnection,
    ServiceUnavailable,
    UpdateRequired,
    ServersTooBusy,
    DuplicateLoginDetected,
    InvalidUser,
    NotAuthorized,
    InvalidSession,
};

