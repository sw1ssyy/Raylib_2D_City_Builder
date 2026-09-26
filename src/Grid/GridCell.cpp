//
// Created by johnc on 28/08/2026.
//

#include "GridCell.h"
#include "../Configs/GameConfig.h"

Rectangle GridCell::GetCellRect() const
{
    return rect;
}

void GridCell::SetCellRect(Rectangle rect)
{
    this->rect = rect;
}

bool GridCell::HasBuilding() const
{
    return hasBuilding;
}

void GridCell::SetBuilding(EBuildingType type)
{
    this->buildingType = type;
    this->hasBuilding = true;
}

EBuildingType GridCell::GetBuildingType() const
{
    return buildingType;
}

Color GridCell::GetBaseCellColor() const
{
    return GameConfig::BASE_COLOUR;
}

Color GridCell::GetHoverCellColor() const
{
    return GameConfig::HOVER_COLOUR;
}
