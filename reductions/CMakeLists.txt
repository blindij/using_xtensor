# The minimum requred cmake version
cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

# project name and language
project(reductions LANGUAGES CXX)

# settings
#include_directories($ENV{HOME}/miniconda3/envs/quantstck/include)
list(APPEND CMAKE_PREFIX_PATH "$ENV{HOME}/local/lib/cmake")
message(STATUS "CMAKE_PREFIX_PATH: ${CMAKE_MODULE_PATH}")
#include(xtl)
#include(xtensor)

find_package(xtl REQUIRED)
find_package(xtensor REQUIRED)

add_executable(reductions main.cpp)


if (MSVC)
    target_compile_options(reductions PRIVATE /EHsc /MP /bigobj)
    set(CMAKE_EXE_LINKER_FLAGS /MANIFEST:NO)
endif()

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
        CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR
(CMAKE_CXX_COMPILER_ID MATCHES "Intel" AND NOT WIN32))
    target_compile_options(reductions PRIVATE -march=native -std=c++14)
endif()

target_link_libraries(reductions xtensor)