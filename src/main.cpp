
#include <vector>

#include "raylib.h"
#include "Configs/GameConfig.h"
#include "cards/CardHolder.h"
#include "Configs/AssetConfig.h"
#include "Grid/Grid.h"
#include "Utils/TextureManager.h"


int main()
{
    InitWindow(GameConfig::SCREEN_WIDTH, GameConfig::SCREEN_HEIGHT, GameConfig::GAME_NAME);

    SetTargetFPS(GameConfig::TARGET_FPS);

    TextureManager::GetInstance().LoadAll();

    CardHolder cardHolder = {};
    Grid grid = {};

    cardHolder.SetupCards();


    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(DARKGRAY);
        DrawText(GameConfig::GAME_NAME, GameConfig::SCREEN_WIDTH / 2 - 220,10 ,60, RED);
        cardHolder.DrawCards();
        grid.DrawGrid();
        EndDrawing();
    }
    TextureManager::GetInstance().UnloadAll();
    CloseWindow();

    return 0;
}
