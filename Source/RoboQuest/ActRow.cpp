#include "ActRow.h"

FActRow::FActRow() {
    this->Act = EActe::Acte1;
    this->TicketByRank[0] = 0;
    this->TicketByRank[1] = 0;
    this->TicketByRank[2] = 0;
    this->TicketByRank[3] = 0;
    this->TicketByRank[4] = 0;
    this->TicketByRank[5] = 0;
    this->EnemyHealthImpactPercentModifier = 0.00f;
    this->EliteHealthImpactPercentModifier = 0.00f;
    this->MultiplayerEnemyHealthImpactPercentModifier = 0.00f;
    this->BossMultiplayerHealthPercentBonus = 0.00f;
    this->BossMultiplayerImpactPercentBonus = 0.00f;
    this->TokenSpeedModifier = 0.00f;
}

