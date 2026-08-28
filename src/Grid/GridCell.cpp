//
// Created by johnc on 28/08/2026.
//

#include "GridCell.h"

Rectangle GridCell::GetCellRect() const
{
    return rect;
}

void GridCell::SetCellRect(Rectangle rect)
{
    this->rect = rect;
}

bool GridCell::IsCellClicked() const
{
    return isClicked;
}

void GridCell::SetCellClicked(bool clicked)
{
    this->isClicked = clicked;
}

Color GridCell::GetBaseCellColor() const
{
    return GameConfig::BASE_COLOUR;
}

Color GridCell::GetHoverCellColor() const
{
    return GameConfig::HOVER_COLOUR;
}

Color GridCell::GetClickedCellColor() const
{
    return GameConfig::CLICKED_COLOUR;
}
