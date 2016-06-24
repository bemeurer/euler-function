cmake_minimum_required(VERSION 3.5)
project(euler-function)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -O3 -lpthread -lgmp -lgmpxx -lprimesieve")

set(SOURCE_FILES
        test.cpp totient.hpp test_extras.hpp)

add_executable(euler_function ${SOURCE_FILES})