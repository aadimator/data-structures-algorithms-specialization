cmake_minimum_required(VERSION 3.5)
project(Week_5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
#    edit_distance.cpp
    knapsack.cpp
#    lcs3.cpp
#    placing_parentheses.cpp
#    primitive_calculator.cpp
        )

add_executable(Week_5 ${SOURCE_FILES})