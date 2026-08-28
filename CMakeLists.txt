cmake_minimum_required(VERSION 3.15)
project(2D_City_Builder)

set(CMAKE_CXX_STANDARD 20)

add_executable(2D_City_Builder main.cpp)

# raylib (prebuilt, vendored in external/raylib)
set(RAYLIB_DIR ${CMAKE_SOURCE_DIR}/external/raylib)

target_include_directories(2D_City_Builder PRIVATE ${RAYLIB_DIR}/include)

# Link the static raylib library
target_link_libraries(2D_City_Builder PRIVATE ${RAYLIB_DIR}/lib/raylib.lib)

# System libraries raylib depends on when linked statically on Windows
if (WIN32)
    target_link_libraries(2D_City_Builder PRIVATE winmm gdi32 opengl32 shell32 user32)
endif ()
