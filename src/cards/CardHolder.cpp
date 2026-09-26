//
// Created by johnc on 28/08/2026.
//

#include "CardHolder.h"

#include "../Configs/GameConfig.h"

CardHolder::CardHolder(Grid& grid) : grid(grid), isCardBeingHeld(false), preHeldCardRect({})
{
}

void CardHolder::SetupCards()
{
    cards.emplace_back(FACTORY, 1, this);
    cards.emplace_back(SHOP, 2, this);
    cards.emplace_back(HOUSE, 3, this);
}

void CardHolder::HoldCard(Card &card)
{
    if (IsCardBeingHeld() && !card.IsBeingHeld())
    {
        return;
    }

    if (!card.IsBeingHeld())
    {
        SetCardBeingHeld(true);

        preHeldCardRect = card.GetCardRect();
    }

    card.SetIsBeingHeld(true);

    card.GetCardRect().x = GetMousePosition().x - GameConfig::CARD_WIDTH / 2;
    card.GetCardRect().y = GetMousePosition().y - GameConfig::CARD_HEIGHT / 2;
}

void CardHolder::ReleaseCard(Card &card)
{
    SetCardBeingHeld(false);

    card.SetIsBeingHeld(false);

    int column = 0;
    int row = 0;

    if (grid.ScreenToTile(GetMousePosition(), column, row))
    {
        grid.CellAt(column, row).SetBuilding(card.GetBuildingType());
    }

    card.GetCardRect() = preHeldCardRect;
}

bool CardHolder::IsCardBeingHeld() const
{
    return this->isCardBeingHeld;
}

void CardHolder::SetCardBeingHeld(bool value)
{
    this->isCardBeingHeld = value;
}

void CardHolder::DrawCards()
{
    for (auto &card : cards)
    {
        card.Draw();
    }
}
