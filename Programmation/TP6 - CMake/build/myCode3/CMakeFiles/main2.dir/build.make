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
CMAKE_SOURCE_DIR = "/home/6ima2/lea.touchard/Bureau/Programmation/TP6 - CMake"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/6ima2/lea.touchard/Bureau/Programmation/TP6 - CMake/build"

# Include any dependencies generated for this target.
include myCode3/CMakeFiles/main2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include myCode3/CMakeFiles/main2.dir/compiler_depend.make

# Include the progress variables for this target.
include myCode3/CMakeFiles/main2.dir/progress.make

# Include the compile flags for this target's objects.
include myCode3/CMakeFiles/main2.dir/flags.make

myCode3/CMakeFiles/main2.dir/src/main2.cpp.o: myCode3/CMakeFiles/main2.dir/flags.make
myCode3/CMakeFiles/main2.dir/src/main2.cpp.o: /home/6ima2/lea.touchard/Bureau/Programmation/TP6\ -\ CMake/myCode3/src/main2.cpp
myCode3/CMakeFiles/main2.dir/src/main2.cpp.o: myCode3/CMakeFiles/main2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/6ima2/lea.touchard/Bureau/Programmation/TP6 - CMake/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object myCode3/CMakeFiles/main2.dir/src/main2.cpp.o"
	cd "/home/6ima2/lea.touchard/Bureau/Programmation/TP6 - CMake/build/myCode3" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT myCode3/CMakeFiles/main2.dir/src/main2.cpp.o -MF CMakeFiles/main2.dir/src/main2.cpp.o.d -o CMakeFiles/main2.dir/src/main2.cpp.o -c "/home/6ima2/lea.touchard/Bureau/Programmation/TP6 - CMake/myCode3/src/main2.cpp"

myCode3/CMakeFiles/main2.dir/src/main2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main2.dir/src/main2.cpp.i"
	cd "/home/6ima2/lea.touchard/Bureau/Programmation/TP6 - CMake/build/myCode3" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/6ima2/lea.touchard/Bureau/Programmation/TP6 - CMake/myCode3/src/main2.cpp" > CMakeFiles/main2.dir/src/main2.cpp.i

myCode3/CMakeFiles/main2.dir/src/main2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main2.dir/src/main2.cpp.s"
	cd "/home/6ima2/lea.touchard/Bureau/Programmation/TP6 - CMake/build/myCode3" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/6ima2/lea.touchard/Bureau/Programmation/TP6 - CMake/myCode3/src/main2.cpp" -o CMakeFiles/main2.dir/src/main2.cpp.s

# Object files for target main2
main2_OBJECTS = \
"CMakeFiles/main2.dir/src/main2.cpp.o"

# External object files for target main2
main2_EXTERNAL_OBJECTS =

bin/main2: myCode3/CMakeFiles/main2.dir/src/main2.cpp.o
bin/main2: myCode3/CMakeFiles/main2.dir/build.make
bin/main2: INTERFACE/libVectorD.a
bin/main2: myCode3/CMakeFiles/main2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/6ima2/lea.touchard/Bureau/Programmation/TP6 - CMake/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/main2"
	cd "/home/6ima2/lea.touchard/Bureau/Programmation/TP6 - CMake/build/myCode3" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
myCode3/CMakeFiles/main2.dir/build: bin/main2
.PHONY : myCode3/CMakeFiles/main2.dir/build

myCode3/CMakeFiles/main2.dir/clean:
	cd "/home/6ima2/lea.touchard/Bureau/Programmation/TP6 - CMake/build/myCode3" && $(CMAKE_COMMAND) -P CMakeFiles/main2.dir/cmake_clean.cmake
.PHONY : myCode3/CMakeFiles/main2.dir/clean

myCode3/CMakeFiles/main2.dir/depend:
	cd "/home/6ima2/lea.touchard/Bureau/Programmation/TP6 - CMake/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/6ima2/lea.touchard/Bureau/Programmation/TP6 - CMake" "/home/6ima2/lea.touchard/Bureau/Programmation/TP6 - CMake/myCode3" "/home/6ima2/lea.touchard/Bureau/Programmation/TP6 - CMake/build" "/home/6ima2/lea.touchard/Bureau/Programmation/TP6 - CMake/build/myCode3" "/home/6ima2/lea.touchard/Bureau/Programmation/TP6 - CMake/build/myCode3/CMakeFiles/main2.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : myCode3/CMakeFiles/main2.dir/depend

