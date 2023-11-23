cmake_minimum_required(VERSION 3.13)


# give a name to the project
project(TP3 LANGUAGES C CXX)

# files to compile
add_executable(TP3 src/main.cpp src/VectorD.cpp src/VectorD.hpp)

# compilation options
target_compile_features(TP3 PRIVATE cxx_std_11) # use at least c++ 11
if (MSVC)
    target_compile_options(TP3 PRIVATE /W3)
else()
    target_compile_options(TP3 PRIVATE -Wall -Wextra -Wpedantic -pedantic-errors)
endif()


