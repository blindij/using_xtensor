# The minimum requred cmake version
cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

# project name and language
project(index_access LANGUAGES CXX)

find_package(xtl REQUIRED)
find_package(xtensor REQUIRED)

add_executable(index_access src/index_access.cpp)

if (MSVC)
   target_compile_options(index_access PRIVATE /EHsc /MP /bigobj)
   set(CMAKE_EXE_LINKER_FLAGS /MANIFEST:NO)
endif()

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
    CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR
    (CMAKE_CXX_COMPILER_ID MATCHES "Intel" AND NOT WIN32))
    target_compile_options(index_access PRIVATE -march=native -std=c++14)
endif()

target_link_libraries(index_access xtensor)

