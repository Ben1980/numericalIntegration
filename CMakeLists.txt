cmake_minimum_required(VERSION 3.13)
project(numericalIntegration)

add_executable(numericalIntegration main.cpp newtonCotes.h gausslegendre.h)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(numericalIntegration PRIVATE fmt::fmt fmt::fmt-header-only)

set(CMAKE_CXX_STANDARD 17)