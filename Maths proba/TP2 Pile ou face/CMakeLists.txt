cmake_minimum_required(VERSION 3.13)


# give a name to the project
project(pile_ou_face LANGUAGES C CXX)

# include Eigen
find_package(Eigen3 REQUIRED)
if(${EIGEN3_FOUND})
    message(STATUS "lib EIGEN3 found")
    message(STATUS "  version " ${EIGEN3_VERSION_STRING})
    message(STATUS "  include " ${EIGEN3_INCLUDE_DIR})
else()
    message(FATAL_ERROR "lib EIGEN3 not found")
endif()


# files to compile
#add_executable(pile_ou_face src/pile_ou_face.cpp)
add_executable(pile_ou_face src/de_6_faces.cpp)

# compilation options
target_compile_features(pile_ou_face PRIVATE cxx_std_11) # use at least c++ 11
if (MSVC)
    target_compile_options(pile_ou_face PRIVATE /W3)
else()
    target_compile_options(pile_ou_face PRIVATE -Wall -Wextra -Wpedantic -pedantic-errors)
endif()

# lib include path
target_include_directories(pile_ou_face PRIVATE "${EIGEN3_INCLUDE_DIR}")


