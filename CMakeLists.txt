cmake_minimum_required(VERSION 3.0.0)
project(UnitTester VERSION 0.1.0)

cmake_minimum_required(VERSION 2.8)

add_subdirectory(cunit)

add_library(avgmax avg_and_max.c)

add_executable(avgmax_test test.c)

target_link_libraries(avgmax_test avgmax cunit)
