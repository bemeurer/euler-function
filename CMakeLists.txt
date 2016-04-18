cmake_minimum_required(VERSION 3.5)
project(euler-function)

ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -O3 -lboost_system -lboost_unit_test_framework -lgmp -lprimesieve")

set(SOURCE_FILES
        test.cpp totient.hpp)

add_executable(euler_function ${SOURCE_FILES})