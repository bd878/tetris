cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(tetris VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXTENSIONS OFF)
set(CMAKE_STANDARD_REQUIRED ON)

find_package(SDL2 REQUIRED COMPONENTS SDL2_image)
if(SDL2_FOUND)
  message(STATUS "SDL2 found witn libraries")
else()
  message(STATUS "SDL2 not found")
endif()

add_library(Entities
  STATIC
    GameObject.cpp
    GameObject.h
    Player.cpp
    Player.h
    Enemy.cpp
    Enemy.h
  )

add_library(TextureManager TextureManager.cpp)
add_library(Game Game.cpp)

target_link_libraries(TextureManager PUBLIC SDL2 SDL2_image)
target_link_libraries(Game PUBLIC TextureManager)

add_executable(tetris main.cpp)

target_link_libraries(tetris SDL2 Game TextureManager Entities)