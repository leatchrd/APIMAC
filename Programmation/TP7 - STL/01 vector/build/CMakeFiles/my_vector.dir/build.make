# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/lib/python3.9/dist-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /usr/local/lib/python3.9/dist-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/6ima2/lea.touchard/Bureau/Programmation/TP7 - STL/01 vector"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/6ima2/lea.touchard/Bureau/Programmation/TP7 - STL/01 vector/build"

# Include any dependencies generated for this target.
include CMakeFiles/my_vector.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/my_vector.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/my_vector.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/my_vector.dir/flags.make

CMakeFiles/my_vector.dir/src/ex3.cpp.o: CMakeFiles/my_vector.dir/flags.make
CMakeFiles/my_vector.dir/src/ex3.cpp.o: /home/6ima2/lea.touchard/Bureau/Programmation/TP7\ -\ STL/01\ vector/src/ex3.cpp
CMakeFiles/my_vector.dir/src/ex3.cpp.o: CMakeFiles/my_vector.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/6ima2/lea.touchard/Bureau/Programmation/TP7 - STL/01 vector/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/my_vector.dir/src/ex3.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/my_vector.dir/src/ex3.cpp.o -MF CMakeFiles/my_vector.dir/src/ex3.cpp.o.d -o CMakeFiles/my_vector.dir/src/ex3.cpp.o -c "/home/6ima2/lea.touchard/Bureau/Programmation/TP7 - STL/01 vector/src/ex3.cpp"

CMakeFiles/my_vector.dir/src/ex3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_vector.dir/src/ex3.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/6ima2/lea.touchard/Bureau/Programmation/TP7 - STL/01 vector/src/ex3.cpp" > CMakeFiles/my_vector.dir/src/ex3.cpp.i

CMakeFiles/my_vector.dir/src/ex3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_vector.dir/src/ex3.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/6ima2/lea.touchard/Bureau/Programmation/TP7 - STL/01 vector/src/ex3.cpp" -o CMakeFiles/my_vector.dir/src/ex3.cpp.s

# Object files for target my_vector
my_vector_OBJECTS = \
"CMakeFiles/my_vector.dir/src/ex3.cpp.o"

# External object files for target my_vector
my_vector_EXTERNAL_OBJECTS =

my_vector: CMakeFiles/my_vector.dir/src/ex3.cpp.o
my_vector: CMakeFiles/my_vector.dir/build.make
my_vector: CMakeFiles/my_vector.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/6ima2/lea.touchard/Bureau/Programmation/TP7 - STL/01 vector/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable my_vector"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/my_vector.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/my_vector.dir/build: my_vector
.PHONY : CMakeFiles/my_vector.dir/build

CMakeFiles/my_vector.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/my_vector.dir/cmake_clean.cmake
.PHONY : CMakeFiles/my_vector.dir/clean

CMakeFiles/my_vector.dir/depend:
	cd "/home/6ima2/lea.touchard/Bureau/Programmation/TP7 - STL/01 vector/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/6ima2/lea.touchard/Bureau/Programmation/TP7 - STL/01 vector" "/home/6ima2/lea.touchard/Bureau/Programmation/TP7 - STL/01 vector" "/home/6ima2/lea.touchard/Bureau/Programmation/TP7 - STL/01 vector/build" "/home/6ima2/lea.touchard/Bureau/Programmation/TP7 - STL/01 vector/build" "/home/6ima2/lea.touchard/Bureau/Programmation/TP7 - STL/01 vector/build/CMakeFiles/my_vector.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/my_vector.dir/depend

