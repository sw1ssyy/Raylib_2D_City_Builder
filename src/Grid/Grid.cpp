//
// Created by johnc on 28/08/2026.
//

#include "Grid.h"

#include <cmath>

#include "../Utils/DrawUtils.h"

Grid::Grid()
{
    SetXOffset((GameConfig::SCREEN_WIDTH - GameConfig::GRID_COLUMNS * GameConfig::CELL_SIZE) / 2.0f);
    SetYOffset((GameConfig::SCREEN_HEIGHT - GameConfig::GRID_ROWS * GameConfig::CELL_SIZE) / 2.0f - GameConfig::GRID_TOP_PADDING);

    for (int row = 0; row < GameConfig::GRID_ROWS; row++)
    {
        for (int col = 0; col < GameConfig::GRID_COLUMNS; col++)
        {
            GridCell cell = {};

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

        DrawRectangleRec(cell.GetCellRect(), cell.GetHoverCellColor());
    }
}

bool Grid::InBounds(int col, int row) const
{
    return col >= 0 && col < GameConfig::GRID_COLUMNS && row >= 0 && row < GameConfig::GRID_ROWS;
}

Vector2 Grid::TileToScreen(int col, int row) const
{
    return {xOffset + (col * GameConfig::CELL_SIZE), yOffset + (row * GameConfig::CELL_SIZE)};
}

Rectangle Grid::CellRect(int col, int row) const
{
    Vector2 pos = TileToScreen(col, row);

    return {pos.x, pos.y, GameConfig::CELL_SIZE, GameConfig::CELL_SIZE};
}

bool Grid::ScreenToTile(Vector2 screenPos, int &col, int &row) const
{
    col = static_cast<int>(std::floor((screenPos.x - xOffset) / GameConfig::CELL_SIZE));
    row = static_cast<int>(std::floor((screenPos.y - yOffset) / GameConfig::CELL_SIZE));
    return InBounds(col, row);
}

GridCell &Grid::CellAt(int col, int row)
{
    return cells[row * GameConfig::GRID_COLUMNS + col];
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
