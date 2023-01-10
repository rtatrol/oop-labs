cmake_minimum_required(VERSION 3.21)
project(Templates)
project(Templates_test)

set(CMAKE_CXX_STANDARD 23)
set(Sources_main main.cpp TupleUtils.h CSVParser.h Out_Overload.h)
add_executable(Templates ${Sources_main})

set(Sources_test test.cpp TupleUtils.h CSVParser.h Out_Overload.h test.cpp)
add_subdirectory(googletest-main)
include_directories(googletest-main/googletest/include)

add_executable(Templates_test ${Sources_test})
target_link_libraries(Templates_test gtest gtest_main)
