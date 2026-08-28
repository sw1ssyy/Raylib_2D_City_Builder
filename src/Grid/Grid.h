//
// Created by johnc on 28/08/2026.
//

#ifndef INC_2D_CITY_BUILDER_GRID_H
#define INC_2D_CITY_BUILDER_GRID_H

#include <vector>

#include "raylib.h"

#include "GridCell.h"

#include "../GameConfig.h"


class Grid
{
public:
    Grid();
    void DrawGrid();
    float GetWidth() const;
    float GetHeight() const;
    std::vector<GridCell> &GetCells();
    float GetXOffset() const;
    float GetYOffset() const;
    void SetXOffset(float xOffset);
    void SetYOffset(float yOffset);

private:
    float width = GameConfig::GridColumns;
    float height = GameConfig::GridRows;
    float xOffset;
    float yOffset;
    std::vector<GridCell> cells;
};


#endif //INC_2D_CITY_BUILDER_GRID_H
