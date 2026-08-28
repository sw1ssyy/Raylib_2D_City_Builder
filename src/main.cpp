
#include <vector>

#include "raylib.h"
#include "GameConfig.h"
#include "Grid/Grid.h"
#include "Utils/DrawUtils.h"


int main()
{
    InitWindow(GameConfig::ScreenWidth, GameConfig::ScreenHeight, GameConfig::GameName);

    SetTargetFPS(GameConfig::TargetFPS);

    Grid grid = {};

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        BeginDrawing();
        ClearBackground(DARKGRAY);
        DrawText("2D City Builder", GameConfig::ScreenWidth / 2 - 220,10 ,60, RED);
        grid.DrawGrid();
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
