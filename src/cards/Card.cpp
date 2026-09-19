//
// Created by johnc on 28/08/2026.
//

#include "Card.h"

#include "../Configs/AssetConfig.h"
#include "../Configs/GameConfig.h"
#include "../Utils/DrawUtils.h"
#include "../Utils/TextureManager.h"

Card::Card(EBuildingType buildingType, int index) :
rect({GameConfig::CARD_X_OFFSET + index * GameConfig::CARD_SPACING, GameConfig::SCREEN_HEIGHT - GameConfig::CARD_BOTTOM_PADDING, GameConfig::CARD_WIDTH, GameConfig::CARD_HEIGHT}),
texture(GetCardTexture(buildingType)),
buildingType(buildingType)

{}

EBuildingType Card::GetBuildingType()
{
    return this->buildingType;
}

Texture2D & Card::GetCardTexture(EBuildingType buildingType)
{
    switch (buildingType)
    {
        case EBuildingType::FACTORY:
            return TextureManager::GetInstance().Get(AssetConfig::FACTORY_CARD);
        case EBuildingType::FARM:
            return TextureManager::GetInstance().Get(AssetConfig::FARM_CARD);
        case EBuildingType::HOUSE:
            return TextureManager::GetInstance().Get(AssetConfig::HOUSE_CARD);
        default:
            return TextureManager::GetInstance().Get(AssetConfig::SHOP_CARD);
    }
}

void Card::Draw()
{
    if (CheckCollisionPointRec(GetMousePosition(), rect))
    {
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            HandleDragMovement();
        }

        DrawUtils::DrawCard(texture,rect,WHITE);

    }
    else
    {
        DrawUtils::DrawCard(texture,rect,LIGHTGRAY);
    }
}

void Card::HandleDragMovement()
{
    rect.x = GetMousePosition().x - GameConfig::CARD_WIDTH / 2;
    rect.y = GetMousePosition().y - GameConfig::CARD_HEIGHT / 2;
}
