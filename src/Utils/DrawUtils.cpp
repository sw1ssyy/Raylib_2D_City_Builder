//
// Created by johnc on 28/08/2026.
//

#include "DrawUtils.h"

#include "TextureManager.h"
#include "../Configs/AssetConfig.h"

namespace
{
    Texture2D& GetBuildingIcon(EBuildingType buildingType)
    {
        switch (buildingType)
        {
            case FACTORY:
                return TextureManager::GetInstance().Get(AssetConfig::ICON_FACTORY);
            case HOUSE:
                return TextureManager::GetInstance().Get(AssetConfig::ICON_HOUSE);
            case SHOP:
                return TextureManager::GetInstance().Get(AssetConfig::ICON_SHOP);
            default:
                return TextureManager::GetInstance().Get(AssetConfig::ICON_FARM);
        }
    }
}

void DrawUtils::DrawCell(const GridCell& cell)
{
    if (cell.HasBuilding())
    {
        Texture2D& icon = GetBuildingIcon(cell.GetBuildingType());
        DrawTexture(icon, cell.GetCellRect().x, cell.GetCellRect().y, WHITE);
    }
    else
    {
        DrawRectangleLines(cell.GetCellRect().x, cell.GetCellRect().y, cell.GetCellRect().width, cell.GetCellRect().height, cell.GetBaseCellColor());
    }
}

void DrawUtils::DrawCard(Texture2D &texture, Rectangle rect, Color color)
{
    DrawTextureEx(texture, {rect.x, rect.y},0,0.4, color);
}
