//
// Created by johnc on 28/08/2026.
//

#ifndef INC_2D_CITY_BUILDER_GAMECONFIG_H
#define INC_2D_CITY_BUILDER_GAMECONFIG_H


struct GameConfig
{
    // Window Setup
    static constexpr int SCREEN_WIDTH  = 1000;
    static constexpr int SCREEN_HEIGHT = 1000;
    static constexpr const char* GAME_NAME = "2D City Builder";
    static constexpr int TARGET_FPS    = 60;

    // Colours
    static constexpr Color HOVER_COLOUR =  {95, 146, 207,100};
    static constexpr Color BASE_COLOUR =  {46, 117, 201,100};
    static constexpr Color CLICKED_COLOUR = {26, 59, 110,100};

    // Grid
    static constexpr int   GRID_COLUMNS   = 15;
    static constexpr int   GRID_ROWS      = 15;
    static constexpr float CELL_SIZE      = 45.0f;
    static constexpr float GRID_TOP_PADDING = 25.0f; // nudges the grid up to visually balance with the title
};


#endif //INC_2D_CITY_BUILDER_GAMECONFIG_H
