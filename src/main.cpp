
#include <vector>

#include "raylib.h"
#include "Configs/GameConfig.h"
#include "cards/CardHolder.h"
#include "Configs/AssetConfig.h"
#include "Grid/Grid.h"
#include "Utils/DrawUtils.h"
#include "Utils/TextureManager.h"


int main()
{
    InitWindow(GameConfig::SCREEN_WIDTH, GameConfig::SCREEN_HEIGHT, GameConfig::GAME_NAME);

    SetTargetFPS(GameConfig::TARGET_FPS);

    TextureManager::GetInstance().Load(AssetConfig::FARM_CARD,AssetConfig::FARM_CARD);
    TextureManager::GetInstance().Load(AssetConfig::FACTORY_CARD,AssetConfig::FACTORY_CARD);
    TextureManager::GetInstance().Load(AssetConfig::HOUSE_CARD,AssetConfig::HOUSE_CARD);
    TextureManager::GetInstance().Load(AssetConfig::SHOP_CARD,AssetConfig::SHOP_CARD);

    Grid grid = {};
    CardHolder cardHolder = {};

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        BeginDrawing();
        ClearBackground(DARKGRAY);
        DrawText(GameConfig::GAME_NAME, GameConfig::SCREEN_WIDTH / 2 - 220,10 ,60, RED);
        cardHolder.DrawCards();
        grid.DrawGrid();
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
