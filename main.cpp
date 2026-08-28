/*******************************************************************************************
*
*   raylib [core] example - delta time
*
*   Example complexity rating: [★☆☆☆] 1/4
*
*   Example originally created with raylib 5.5, last time updated with raylib 6.0
*
*   Example contributed by Robin (@RobinsAviary) and reviewed by Ramon Santamaria (@raysan5)
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2025 Robin (@RobinsAviary)
*
********************************************************************************************/

#include "raylib.h"


int main(void)
{

    const int screenWidth = 800;
    const int screenHeight = 450;

    const int currentFPS = 60;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - delta time");

    SetTargetFPS(currentFPS);

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {

    }
    CloseWindow();        // Close window and OpenGL context


    return 0;
}