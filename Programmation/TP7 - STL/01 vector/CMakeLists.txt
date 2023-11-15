cmake_minimum_required(VERSION 3.16)

# give a name to the project
project(my_vector LANGUAGES C CXX)

# display compiler name and version
message("compiler         : " ${CMAKE_CXX_COMPILER_ID})
message("compiler version : " ${CMAKE_CXX_COMPILER_VERSION})
message("compiler variant : " ${CMAKE_CXX_COMPILER_FRONTEND_VARIANT})


# files to compile
add_executable(my_vector src/ex3.cpp)


# compilation options
target_compile_features(my_vector PRIVATE cxx_std_11) # use at least c++ 11
if (MSVC)
    target_compile_options(my_vector PRIVATE /W3)
else()
    target_compile_options(my_vector PRIVATE -Wall -Wextra -Wpedantic -pedantic-errors)
endif()