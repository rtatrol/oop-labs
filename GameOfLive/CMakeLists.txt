cmake_minimum_required(VERSION 3.21)
project(GameOfLive)

set(CMAKE_CXX_STANDARD 23)
set(SFML_DIR SFML-2.5.1/lib/cmake/SFML)
find_package(SFML COMPONENTS graphics audio REQUIRED)

add_subdirectory(googletest-main)
include_directories(googletest-main/googletest/include)

add_executable(GameOfLive main.cpp gtest.h Objects.h InputFileParser.h)

target_link_libraries(GameOfLive gtest gtest_main)

target_link_libraries(GameOfLive sfml-graphics sfml-audio)
install(TARGETS GameOfLive DESTINATION bin)
