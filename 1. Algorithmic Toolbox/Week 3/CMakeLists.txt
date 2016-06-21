cmake_minimum_required(VERSION 3.5)
project(Week_3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    change.cpp
#    covering_segments.cpp
#    different_summands.cpp
#    dot_product.cpp
#    fractional_knapsack.cpp
        )

add_executable(Week_3 ${SOURCE_FILES})