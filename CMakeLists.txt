cmake_minimum_required(VERSION 3.1...3.21)

project(
  Snake
  VERSION 1.0
  LANGUAGES CXX)


add_library(graphics src/graphics/nCursesTest.cpp include/graphics/nCursesTest.hpp)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(Snake src/main.cpp)

target_link_libraries(Snake PRIVATE graphics)
target_link_libraries(Snake PRIVATE ${CURSES_LIBRARIES})