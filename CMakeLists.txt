cmake_minimum_required(VERSION 3.0.0)
project(UnitTester VERSION 0.1.0)

cmake_minimum_required(VERSION 2.8)

add_subdirectory(cunit)

add_library(avgmax avg_and_max.c)
set_property(TARGET avgmax PROPERTY C_STANDARD 99)

add_executable(avgmax_test test.c)
set_property(TARGET avgmax_test PROPERTY C_STANDARD 99)

target_link_libraries(avgmax_test avgmax cunit)
