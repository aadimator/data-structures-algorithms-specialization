cmake_minimum_required(VERSION 3.6)
project(Week_3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        #    hash_chains.cpp
        hash_substring.cpp
        #    phone_book.cpp
        )

add_executable(Week_3 ${SOURCE_FILES})