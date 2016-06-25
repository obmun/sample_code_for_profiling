cmake_minimum_required(VERSION 3.0)
project(perf_analysis_example_code)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native -std=c++14 -Wall")

add_library(library SHARED library.cpp)

add_executable(app app.cpp)
target_link_libraries(app library)
