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

float GridCell::GetSize() const
{
    return size;
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
    return baseCellColour;
}

Color GridCell::GetHoverCellColor() const
{
    return hoverCellColour;
}

Color GridCell::GetClickedCellColor() const
{
    return clickedCellColour;
}
