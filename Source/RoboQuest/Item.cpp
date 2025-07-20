#include "Item.h"

FItem::FItem() {
    this->FeedbackType = EPerkFeedbackType::None;
    this->bMultiplayerOnly = false;
    this->bLootable = false;
    this->bIsDisplay = false;
    this->Cost = 0;
    this->bExcludeForSuperbot = false;
    this->bHaveQuantity = false;
    this->Quantity = 0;
    this->Rarity = EItemRarity::Common;
    this->bLootableInChest = false;
}

