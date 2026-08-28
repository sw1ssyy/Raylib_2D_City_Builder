//
// Created by johnc on 28/08/2026.
//

#ifndef INC_2D_CITY_BUILDER_GAMECONFIG_H
#define INC_2D_CITY_BUILDER_GAMECONFIG_H


struct GameConfig
{
    // Window Setup
    static constexpr int ScreenWidth  = 1000;
    static constexpr int ScreenHeight = 1000;
    static constexpr const char* GameName = "2D City Builder";
    static constexpr int TargetFPS    = 60;

    // Grid
    static constexpr int   GridColumns = 15;
    static constexpr int   GridRows    = 15;
    static constexpr float CellSize    = 45.0f;
};


#endif //INC_2D_CITY_BUILDER_GAMECONFIG_H
