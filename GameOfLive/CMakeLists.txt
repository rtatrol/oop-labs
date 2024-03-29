cmake_minimum_required(VERSION 3.21)
project(GameOfLive)
project(GameOfLive_TEST)

set(Sources main.cpp InputFileParser.h Board.h InputFileParser.cpp Board.cpp Cage.h Cage.cpp LiveSpace.h)
set(Sources_test test.cpp InputFileParser.h Board.h InputFileParser.cpp Board.cpp Cage.h Cage.cpp LiveSpace.h)

set(CMAKE_CXX_STANDARD 23)
set(SFML_DIR SFML-2.5.1/lib/cmake/SFML)
find_package(SFML COMPONENTS graphics audio REQUIRED)

add_subdirectory(googletest-main)
include_directories(googletest-main/googletest/include)

add_executable(GameOfLive ${Sources})
add_executable(GameOfLive_Test ${Sources_test})

target_link_libraries(GameOfLive_Test gtest gtest_main sfml-graphics sfml-audio)

target_link_libraries(GameOfLive sfml-graphics sfml-audio)
install(TARGETS GameOfLive DESTINATION bin)