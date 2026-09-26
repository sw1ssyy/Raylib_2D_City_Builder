//
// Created by johnc on 28/08/2026.
//

#ifndef INC_2D_CITY_BUILDER_GRIDCELL_H
#define INC_2D_CITY_BUILDER_GRIDCELL_H
#include "raylib.h"

#include "../cards/Card.h"


class GridCell
{
    public:
    Rectangle GetCellRect() const;
    void SetCellRect(Rectangle rectangle);
    bool HasBuilding() const;
    void SetBuilding(EBuildingType type);
    EBuildingType GetBuildingType() const;
    Color GetBaseCellColor() const;
    Color GetHoverCellColor() const;

    private:
    Rectangle rect = {};
    bool hasBuilding = false;
    EBuildingType buildingType = {};
};


#endif //INC_2D_CITY_BUILDER_GRIDCELL_H
