//
// Created by johnc on 28/08/2026.
//

#include "CardHolder.h"

CardHolder::CardHolder(): cards({Card(EBuildingType::FARM), Card(EBuildingType::FACTORY), Card(EBuildingType::FACTORY)})
{};

void CardHolder::DrawCards()
{
    for (int i = 0; i < cards.size(); i++)
    {
        Card& card = cards[i];
        DrawCard(card, i);
    }
}

void CardHolder::DrawCard(Card& card, int x)
{
    card.Draw(x);
}
