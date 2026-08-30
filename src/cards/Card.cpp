//
// Created by johnc on 28/08/2026.
//

#include "Card.h"

#include "../Configs/AssetConfig.h"
#include "../Configs/GameConfig.h"
#include "../Utils/TextureManager.h"

Card::Card(EBuildingType buildingType) : rect({})
{
    this->buildingType = buildingType;
}

EBuildingType Card::GetBuildingType()
{
    return this->buildingType;
}

void Card::Draw(int x)
{
    float xValue = GameConfig::CARD_X_OFFSET + x * GameConfig::CARD_SPACING;

    rect = {static_cast<float>(xValue), GameConfig::SCREEN_HEIGHT - GameConfig::CARD_BOTTOM_PADDING, GameConfig::CARD_WIDTH, GameConfig::CARD_HEIGHT};

    if (CheckCollisionPointRec(GetMousePosition(), rect))
    {
        DrawTextureEx(TextureManager::GetInstance().Get(x % 2 == 0? AssetConfig::SHOP_CARD : AssetConfig::HOUSE_CARD),{xValue, GameConfig::SCREEN_HEIGHT - GameConfig::CARD_BOTTOM_PADDING},0,0.4, WHITE);
    }
    else
    {
        DrawTextureEx(TextureManager::GetInstance().Get(x % 2 == 0? AssetConfig::SHOP_CARD : AssetConfig::HOUSE_CARD),{xValue, GameConfig::SCREEN_HEIGHT - GameConfig::CARD_BOTTOM_PADDING},0,0.4, LIGHTGRAY);
    }
}
