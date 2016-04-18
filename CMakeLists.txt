cmake_minimum_required(VERSION 3.5)
project(euler_function)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -O3 -lboost_system -lboost_thread -lgmp -lprimesieve")

set(SOURCE_FILES
        test.cpp totient.hpp)

add_executable(euler_function ${SOURCE_FILES})