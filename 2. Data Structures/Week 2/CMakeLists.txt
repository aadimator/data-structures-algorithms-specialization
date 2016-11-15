cmake_minimum_required(VERSION 3.6)
project(Week_2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
#        build_heap.cpp
       job_queue.cpp
#       merging_tables.cpp
        )

add_executable(Week_2 ${SOURCE_FILES})