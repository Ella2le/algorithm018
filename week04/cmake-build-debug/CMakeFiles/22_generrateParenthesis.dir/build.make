# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/lewang/clion-2018.3.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/lewang/clion-2018.3.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lewang/algorithm018/week04

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lewang/algorithm018/week04/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/22_generrateParenthesis.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/22_generrateParenthesis.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/22_generrateParenthesis.dir/flags.make

CMakeFiles/22_generrateParenthesis.dir/22_generrateParenthesis.cpp.o: CMakeFiles/22_generrateParenthesis.dir/flags.make
CMakeFiles/22_generrateParenthesis.dir/22_generrateParenthesis.cpp.o: ../22_generrateParenthesis.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lewang/algorithm018/week04/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/22_generrateParenthesis.dir/22_generrateParenthesis.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/22_generrateParenthesis.dir/22_generrateParenthesis.cpp.o -c /home/lewang/algorithm018/week04/22_generrateParenthesis.cpp

CMakeFiles/22_generrateParenthesis.dir/22_generrateParenthesis.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/22_generrateParenthesis.dir/22_generrateParenthesis.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lewang/algorithm018/week04/22_generrateParenthesis.cpp > CMakeFiles/22_generrateParenthesis.dir/22_generrateParenthesis.cpp.i

CMakeFiles/22_generrateParenthesis.dir/22_generrateParenthesis.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/22_generrateParenthesis.dir/22_generrateParenthesis.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lewang/algorithm018/week04/22_generrateParenthesis.cpp -o CMakeFiles/22_generrateParenthesis.dir/22_generrateParenthesis.cpp.s

# Object files for target 22_generrateParenthesis
22_generrateParenthesis_OBJECTS = \
"CMakeFiles/22_generrateParenthesis.dir/22_generrateParenthesis.cpp.o"

# External object files for target 22_generrateParenthesis
22_generrateParenthesis_EXTERNAL_OBJECTS =

22_generrateParenthesis: CMakeFiles/22_generrateParenthesis.dir/22_generrateParenthesis.cpp.o
22_generrateParenthesis: CMakeFiles/22_generrateParenthesis.dir/build.make
22_generrateParenthesis: CMakeFiles/22_generrateParenthesis.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lewang/algorithm018/week04/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 22_generrateParenthesis"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/22_generrateParenthesis.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/22_generrateParenthesis.dir/build: 22_generrateParenthesis

.PHONY : CMakeFiles/22_generrateParenthesis.dir/build

CMakeFiles/22_generrateParenthesis.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/22_generrateParenthesis.dir/cmake_clean.cmake
.PHONY : CMakeFiles/22_generrateParenthesis.dir/clean

CMakeFiles/22_generrateParenthesis.dir/depend:
	cd /home/lewang/algorithm018/week04/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lewang/algorithm018/week04 /home/lewang/algorithm018/week04 /home/lewang/algorithm018/week04/cmake-build-debug /home/lewang/algorithm018/week04/cmake-build-debug /home/lewang/algorithm018/week04/cmake-build-debug/CMakeFiles/22_generrateParenthesis.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/22_generrateParenthesis.dir/depend

