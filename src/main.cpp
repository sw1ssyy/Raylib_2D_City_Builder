
#include <vector>

#include "raylib.h"
#include "GameConfig.h"
#include "Grid/Grid.h"
#include "Utils/DrawUtils.h"


int main()
{
    InitWindow(GameConfig::SCREEN_WIDTH, GameConfig::SCREEN_HEIGHT, GameConfig::GAME_NAME);

    SetTargetFPS(GameConfig::TARGET_FPS);

    Grid grid = {};

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        BeginDrawing();
        ClearBackground(DARKGRAY);
        DrawText(GameConfig::GAME_NAME, GameConfig::SCREEN_WIDTH / 2 - 220,10 ,60, RED);
        grid.DrawGrid();
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
