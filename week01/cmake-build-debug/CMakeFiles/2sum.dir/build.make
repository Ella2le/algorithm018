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
CMAKE_SOURCE_DIR = /home/lewang/algorithm018/week01

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lewang/algorithm018/week01/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/2sum.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/2sum.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/2sum.dir/flags.make

CMakeFiles/2sum.dir/2sum.cpp.o: CMakeFiles/2sum.dir/flags.make
CMakeFiles/2sum.dir/2sum.cpp.o: ../2sum.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lewang/algorithm018/week01/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/2sum.dir/2sum.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/2sum.dir/2sum.cpp.o -c /home/lewang/algorithm018/week01/2sum.cpp

CMakeFiles/2sum.dir/2sum.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2sum.dir/2sum.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lewang/algorithm018/week01/2sum.cpp > CMakeFiles/2sum.dir/2sum.cpp.i

CMakeFiles/2sum.dir/2sum.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2sum.dir/2sum.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lewang/algorithm018/week01/2sum.cpp -o CMakeFiles/2sum.dir/2sum.cpp.s

# Object files for target 2sum
2sum_OBJECTS = \
"CMakeFiles/2sum.dir/2sum.cpp.o"

# External object files for target 2sum
2sum_EXTERNAL_OBJECTS =

2sum: CMakeFiles/2sum.dir/2sum.cpp.o
2sum: CMakeFiles/2sum.dir/build.make
2sum: CMakeFiles/2sum.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lewang/algorithm018/week01/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 2sum"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/2sum.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/2sum.dir/build: 2sum

.PHONY : CMakeFiles/2sum.dir/build

CMakeFiles/2sum.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/2sum.dir/cmake_clean.cmake
.PHONY : CMakeFiles/2sum.dir/clean

CMakeFiles/2sum.dir/depend:
	cd /home/lewang/algorithm018/week01/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lewang/algorithm018/week01 /home/lewang/algorithm018/week01 /home/lewang/algorithm018/week01/cmake-build-debug /home/lewang/algorithm018/week01/cmake-build-debug /home/lewang/algorithm018/week01/cmake-build-debug/CMakeFiles/2sum.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/2sum.dir/depend
