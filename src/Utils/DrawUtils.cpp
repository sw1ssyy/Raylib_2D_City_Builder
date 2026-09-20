//
// Created by johnc on 28/08/2026.
//

#include "DrawUtils.h"

#include "TextureManager.h"
#include "../Configs/AssetConfig.h"

void DrawUtils::DrawCell(const GridCell& cell)
{
    if (cell.IsCellClicked())
    {
        DrawTexture(TextureManager::GetInstance().Get(AssetConfig::ICON_FARM),cell.GetCellRect().x, cell.GetCellRect().y, WHITE);
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
