//
// Created by johnc on 28/08/2026.
//

#ifndef INC_2D_CITY_BUILDER_CARD
#define INC_2D_CITY_BUILDER_CARD
#include "raylib.h"

class CardHolder;

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

    Card(EBuildingType buildingType, int index, CardHolder* holder);

    EBuildingType GetBuildingType() const;

    void Draw();

    bool IsBeingHeld() const;

    void SetIsBeingHeld(bool value);

    Rectangle& GetCardRect();

    private:
    Texture2D& GetCardTexture(EBuildingType buildingType);
    EBuildingType buildingType;
    Texture2D& texture;
    Rectangle rect;
    CardHolder* holder;
    bool heldStatus;
};




#endif //INC_2D_CITY_BUILDER_CARD
