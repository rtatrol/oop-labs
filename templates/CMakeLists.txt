cmake_minimum_required(VERSION 3.21)
project(Templates)

set(CMAKE_CXX_STANDARD 23)
set(Sources main.cpp TupleUtils.h CSVParser.h)
add_executable(Templates ${Sources})