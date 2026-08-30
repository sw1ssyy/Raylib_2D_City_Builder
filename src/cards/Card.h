//
// Created by johnc on 28/08/2026.
//

#ifndef INC_2D_CITY_BUILDER_CARD
#define INC_2D_CITY_BUILDER_CARD
#include "raylib.h"

enum EBuildingType
{
    FARM,
    HOUSE,
    SHOP,
    FACTORY,
};

class Card
{
    public:
    Card(EBuildingType buildingType);
    EBuildingType GetBuildingType();
    void Draw(int x);
    private:
    EBuildingType buildingType;
    Rectangle rect;
};




#endif //INC_2D_CITY_BUILDER_CARD
