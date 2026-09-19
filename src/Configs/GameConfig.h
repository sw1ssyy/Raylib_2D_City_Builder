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
    static constexpr int   GRID_COLUMNS   = 9;
    static constexpr int   GRID_ROWS      = 7;
    static constexpr float CELL_SIZE      = 75.0f;
    static constexpr float GRID_TOP_PADDING = 25.0f; // nudges the grid up to visually balance with the title

    // Cards
    static constexpr float CARD_WIDTH = 100.0f;
    static constexpr float CARD_HEIGHT = 140.0f;
    static constexpr float CARD_SPACING = 120.0f;
    static constexpr float CARD_X_OFFSET = SCREEN_WIDTH * 0.2;
    static constexpr float CARD_BOTTOM_PADDING = 150.0f;
};


#endif //INC_2D_CITY_BUILDER_GAMECONFIG_H
