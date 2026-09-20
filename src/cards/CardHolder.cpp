//
// Created by johnc on 28/08/2026.
//

#include "CardHolder.h"

CardHolder::CardHolder(): cards({ Card(EBuildingType::FACTORY, 0), Card(EBuildingType::SHOP, 1)})
{};

void CardHolder::DrawCards()
{
    for (int i = 0; i < cards.size(); i++)
    {
        cards[i].Draw();
    }
}
