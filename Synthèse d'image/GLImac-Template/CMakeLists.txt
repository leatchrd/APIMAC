# ---Choose CMake version---
cmake_minimum_required(VERSION 3.20)

# ---Choose project name---
project(ImacGL)

# ---Add p6 library---
include(FetchContent)
set(P6_RAW_OPENGL_MODE ON CACHE BOOL "")
FetchContent_Declare(
    p6
    GIT_REPOSITORY https://github.com/julesfouchy/p6
    GIT_TAG c962f8c5f3bf8324482facaf2ec178ef4c9aefaa
)
FetchContent_MakeAvailable(p6)


set(OpenGL_GL_PREFERENCE LEGACY)

add_definitions(-std=c++11)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake)

find_package(SDL REQUIRED)
find_package(OpenGL REQUIRED)
#find_package(GLEW REQUIRED)

# Pour gérer un bug a la fac, a supprimer sur machine perso:
set(OPENGL_LIBRARIES /usr/lib/x86_64-linux-gnu/libGL.so.1)

set(GLEW_LIBRARY ${CMAKE_SOURCE_DIR}/third-party/libGLEW.a)

include_directories(${SDL_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIR} glimac/include third-party/include)

set(ALL_LIBRARIES glimac ${SDL_LIBRARY} ${OPENGL_LIBRARIES} ${GLEW_LIBRARY})

add_subdirectory(glimac)

file(GLOB TP_DIRECTORIES "TP*")

foreach(TP ${TP_DIRECTORIES})
    add_subdirectory(${TP})
endforeach()
