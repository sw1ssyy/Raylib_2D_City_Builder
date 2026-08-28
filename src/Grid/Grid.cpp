//
// Created by johnc on 28/08/2026.
//

#include "Grid.h"

#include <cmath>

#include "../Utils/DrawUtils.h"

Grid::Grid()
{
    SetXOffset((GameConfig::ScreenWidth - GameConfig::GridColumns * GameConfig::CellSize) / 2.0f);
    SetYOffset((GameConfig::ScreenHeight - GameConfig::GridRows * GameConfig::CellSize) / 2.0f - GameConfig::GridTopPadding);

    for (int row = 0; row < GameConfig::GridRows; row++)
    {
        for (int col = 0; col < GameConfig::GridColumns; col++)
        {
            GridCell cell = {};

            cell.SetCellClicked(false);
            cell.SetCellRect(CellRect(col, row));

            GetCells().emplace_back(cell);
        }
    }
}

void Grid::DrawGrid()
{
    for (GridCell& cell: GetCells())
    {
        DrawUtils::DrawCell(cell);
    }

    int col, row;
    if (ScreenToTile(GetMousePosition(), col, row))
    {
        GridCell& cell = CellAt(col, row);

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            cell.SetCellClicked(!cell.IsCellClicked());
        }

        DrawRectangleRec(cell.GetCellRect(),cell.IsCellClicked() ? cell.GetClickedCellColor() : cell.GetHoverCellColor());
    }
}

bool Grid::InBounds(int col, int row) const
{
    return col >= 0 && col < GameConfig::GridColumns && row >= 0 && row < GameConfig::GridRows;
}

Vector2 Grid::TileToScreen(int col, int row) const
{
    return {xOffset + (col * GameConfig::CellSize), yOffset + (row * GameConfig::CellSize)};
}

Rectangle Grid::CellRect(int col, int row) const
{
    Vector2 pos = TileToScreen(col, row);

    return {pos.x, pos.y, GameConfig::CellSize, GameConfig::CellSize};
}

bool Grid::ScreenToTile(Vector2 screenPos, int &col, int &row) const
{
    col = static_cast<int>(std::floor((screenPos.x - xOffset) / GameConfig::CellSize));
    row = static_cast<int>(std::floor((screenPos.y - yOffset) / GameConfig::CellSize));
    return InBounds(col, row);
}

GridCell &Grid::CellAt(int col, int row)
{
    return cells[row * GameConfig::GridColumns + col];
}

std::vector<GridCell> &Grid::GetCells()
{
    return cells;
}

float Grid::GetXOffset() const
{
    return xOffset;
}

float Grid::GetYOffset() const
{
    return yOffset;
}

void Grid::SetXOffset(float xOffset)
{
    this->xOffset = xOffset;
}

void Grid::SetYOffset(float yOffset)
{
    this->yOffset = yOffset;
}
