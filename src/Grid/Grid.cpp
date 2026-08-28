//
// Created by johnc on 28/08/2026.
//

#include "Grid.h"

#include "../Utils/DrawUtils.h"

Grid::Grid()
{
    SetXOffset(((GameConfig::ScreenWidth / 2) - (GetWidth() / 2)) - GetWidth() / 2 * GameConfig::CellSize);
    SetYOffset(((GameConfig::ScreenHeight / 2) - (GetHeight() / 2)) - GetHeight() / 2 * GameConfig::CellSize - 25);

    for (int i = 0; i < GameConfig::GridColumns; i++)
    {
        for (int j = 0; j < GameConfig::GridRows; j++)
        {
            GridCell cell = {};

            cell.SetCellClicked(false);

            cell.SetCellRect({GetXOffset() + (j * cell.GetSize()), GetYOffset() + (i * cell.GetSize()), cell.GetSize(), cell.GetSize()});

            GetCells().emplace_back(cell);
        }
    }
}

void Grid::DrawGrid()
{
    for (GridCell& cell: GetCells())
    {
        if (CheckCollisionPointRec(GetMousePosition(), cell.GetCellRect()))
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                cell.SetCellClicked(!cell.IsCellClicked());
                DrawRectangleRec(cell.GetCellRect(),cell.GetClickedCellColor());
            }
            else
            {
                DrawRectangleRec(cell.GetCellRect(),cell.GetHoverCellColor());
            }
        }
        else
        {
            DrawUtils::DrawCell(cell);
        }
    }
}

float Grid::GetWidth() const
{
    return width;
}

float Grid::GetHeight() const
{
    return height;
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
