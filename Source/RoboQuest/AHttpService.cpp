#include "AHttpService.h"

AAHttpService::AAHttpService(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void AAHttpService::SendUIScreenshot() {
}

void AAHttpService::SendTextData() {
}

void AAHttpService::SendInfiniteGameData(FRequest_InfiniteGame InfiniteGameData) {
}

void AAHttpService::SendGameData(FRequest_Game GameData) {
}

void AAHttpService::SendFeedback(FRequest_Feedback FeedbackRequest) {
}

void AAHttpService::SendCrash(FRequest_Crash CrashData) {
}

void AAHttpService::OnUIScreenshotFinished(int32 InSizeX, int32 InSizeY, const TArray<FColor>& InImageData) {
}


