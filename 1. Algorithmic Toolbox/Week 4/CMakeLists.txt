cmake_minimum_required(VERSION 3.5)
project(Week_4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    binary_search.cpp
#    inversions.cpp
#    majority_element.cpp
#    points_and_segments.cpp
#    sorting.cpp
        )

add_executable(Week_4 ${SOURCE_FILES})