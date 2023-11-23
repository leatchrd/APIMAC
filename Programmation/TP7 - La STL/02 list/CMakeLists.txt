cmake_minimum_required(VERSION 3.13)

# give a name to the project
project(my_lsit LANGUAGES C CXX)

# files to compile
add_executable(my_lsit src/main.cpp)

# compilation options
target_compile_features(my_lsit PRIVATE cxx_std_11) # use at least c++ 11
if (MSVC)
    target_compile_options(my_lsit PRIVATE /W3)
else()
    target_compile_options(my_lsit PRIVATE -Wall -Wextra -Wpedantic -pedantic-errors)
endif()
