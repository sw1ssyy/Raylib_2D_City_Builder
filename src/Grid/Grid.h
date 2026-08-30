//
// Created by johnc on 28/08/2026.
//

#ifndef INC_2D_CITY_BUILDER_GRID_H
#define INC_2D_CITY_BUILDER_GRID_H

#include <vector>

#include "raylib.h"

#include "GridCell.h"

#include "../Configs/GameConfig.h"


class Grid
{
public:
    Grid();

    void DrawGrid();

    std::vector<GridCell> &GetCells();

    float GetXOffset() const;

    float GetYOffset() const;

    void SetXOffset(float xOffset);

    void SetYOffset(float yOffset);

    /// True if (col, row) refers to a cell that exists in the grid.
    bool InBounds(int col, int row) const;

    /// Screen-pixel position of the top-left corner of cell (col, row).
    Vector2 TileToScreen(int col, int row) const;

    /// Screen-space rectangle covering cell (col, row).
    Rectangle CellRect(int col, int row) const;

    /// Converts a screen-pixel position to tile indices; returns false (and leaves col/row off-grid) when the point is outside the grid.
    bool ScreenToTile(Vector2 screenPos, int &col, int &row) const;

    /// Reference to the cell at (col, row); caller must ensure the indices are in bounds.
    GridCell &CellAt(int col, int row);

private:
    float xOffset = 0;
    float yOffset = 0;
    std::vector<GridCell> cells;
};


#endif //INC_2D_CITY_BUILDER_GRID_H
