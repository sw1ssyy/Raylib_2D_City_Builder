//
// Created by johnc on 28/08/2026.
//

#ifndef INC_2D_CITY_BUILDER_GRIDCELL_H
#define INC_2D_CITY_BUILDER_GRIDCELL_H
#include "raylib.h"

#include "../GameConfig.h"


class GridCell
{
    public:
    Rectangle GetCellRect() const;
    void SetCellRect(Rectangle rectangle);
    bool IsCellClicked() const;
    void SetCellClicked(bool clicked);
    Color GetBaseCellColor() const;
    Color GetHoverCellColor() const;
    Color GetClickedCellColor() const;

    private:
    Rectangle rect = {};
    bool isClicked = false;
};


#endif //INC_2D_CITY_BUILDER_GRIDCELL_H
