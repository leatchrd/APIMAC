cmake_minimum_required(VERSION 3.15)

project(random)

# file to comile
add_executable(random src/Rand.cpp)

# compilation options
target_compile_features(random PRIVATE cxx_std_11) # use at least c++ 11
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    # using Clang
    message(STATUS "compiling with clang")
    target_compile_options(random PRIVATE -Wall -Wextra -Wpedantic -pedantic-errors -Wno-unknown-warning-option -Wno-unused-private-field -Wno-unused-variable)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    # using GCC
    message(STATUS "compiling with GCC")
    target_compile_options(random PRIVATE -Wall -Wextra -Wpedantic -pedantic-errors -Wno-unknown-warning-option  -Wno-unused-variable -Wno-comment)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
    message(STATUS "compiling with intel")
    # using Intel C++
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    # using Visual Studio C++
    message(STATUS "compiling with MSVC")
    target_compile_options(random PRIVATE /W3)
endif()
