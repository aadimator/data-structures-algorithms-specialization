cmake_minimum_required(VERSION 3.5)
project(Week_2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
#    fib.cc
#    fibonacci_huge.cpp
    fibonacci_last_digit.cpp
#    gcd.cpp
#    lcm.cpp
        )
add_executable(Week_2 ${SOURCE_FILES})