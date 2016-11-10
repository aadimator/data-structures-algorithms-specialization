cmake_minimum_required(VERSION 3.5)
project(Week_1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        check_brackets_in_code/check_brackets.cpp
#        network_packet_processing_simulation/process_packages.cpp
#        tree_height/tree-height.cpp
        )

add_executable(Week_1 ${SOURCE_FILES})