cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(tetris VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXTENSIONS OFF)
set(CMAKE_STANDARD_REQUIRED ON)

find_package(SDL2 REQUIRED)
if(SDL2_FOUND)
  message(STATUS "SDL2 found")
else()
  message(STATUS "SDL2 not found")
endif()

add_executable(tetris main.cpp)

target_link_libraries(tetris SDL2)