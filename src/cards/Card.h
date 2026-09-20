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

    Card(EBuildingType buildingType, int index);

    EBuildingType GetBuildingType();

    void HandleDragMovement();

    void Draw();

    private:
    Texture2D& GetCardTexture(EBuildingType buildingType);
    EBuildingType buildingType;
    Texture2D& texture;
    Rectangle rect;
};




#endif //INC_2D_CITY_BUILDER_CARD
