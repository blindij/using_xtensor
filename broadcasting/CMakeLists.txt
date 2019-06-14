# The minimum requred cmake version
cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

# project name and language
project(broadcasting LANGUAGES CXX)

find_package(xtl REQUIRED)
find_package(xtensor REQUIRED)

add_executable(broadcasting src/broadcasting.cpp)

if (MSVC)
   target_compile_options(broadcasting PRIVATE /EHsc /MP /bigobj)
   set(CMAKE_EXE_LINKER_FLAGS /MANIFEST:NO)
endif()

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
    CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR
    (CMAKE_CXX_COMPILER_ID MATCHES "Intel" AND NOT WIN32))
    target_compile_options(broadcasting PRIVATE -march=native -std=c++14)
endif()

target_link_libraries(broadcasting xtensor)
