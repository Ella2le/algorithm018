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
CMAKE_SOURCE_DIR = /home/lewang/algorithm018/week02

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lewang/algorithm018/week02/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/49_UglyNumber.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/49_UglyNumber.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/49_UglyNumber.dir/flags.make

CMakeFiles/49_UglyNumber.dir/49_UglyNumber.cpp.o: CMakeFiles/49_UglyNumber.dir/flags.make
CMakeFiles/49_UglyNumber.dir/49_UglyNumber.cpp.o: ../49_UglyNumber.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lewang/algorithm018/week02/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/49_UglyNumber.dir/49_UglyNumber.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/49_UglyNumber.dir/49_UglyNumber.cpp.o -c /home/lewang/algorithm018/week02/49_UglyNumber.cpp

CMakeFiles/49_UglyNumber.dir/49_UglyNumber.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/49_UglyNumber.dir/49_UglyNumber.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lewang/algorithm018/week02/49_UglyNumber.cpp > CMakeFiles/49_UglyNumber.dir/49_UglyNumber.cpp.i

CMakeFiles/49_UglyNumber.dir/49_UglyNumber.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/49_UglyNumber.dir/49_UglyNumber.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lewang/algorithm018/week02/49_UglyNumber.cpp -o CMakeFiles/49_UglyNumber.dir/49_UglyNumber.cpp.s

# Object files for target 49_UglyNumber
49_UglyNumber_OBJECTS = \
"CMakeFiles/49_UglyNumber.dir/49_UglyNumber.cpp.o"

# External object files for target 49_UglyNumber
49_UglyNumber_EXTERNAL_OBJECTS =

49_UglyNumber: CMakeFiles/49_UglyNumber.dir/49_UglyNumber.cpp.o
49_UglyNumber: CMakeFiles/49_UglyNumber.dir/build.make
49_UglyNumber: CMakeFiles/49_UglyNumber.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lewang/algorithm018/week02/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 49_UglyNumber"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/49_UglyNumber.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/49_UglyNumber.dir/build: 49_UglyNumber

.PHONY : CMakeFiles/49_UglyNumber.dir/build

CMakeFiles/49_UglyNumber.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/49_UglyNumber.dir/cmake_clean.cmake
.PHONY : CMakeFiles/49_UglyNumber.dir/clean

CMakeFiles/49_UglyNumber.dir/depend:
	cd /home/lewang/algorithm018/week02/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lewang/algorithm018/week02 /home/lewang/algorithm018/week02 /home/lewang/algorithm018/week02/cmake-build-debug /home/lewang/algorithm018/week02/cmake-build-debug /home/lewang/algorithm018/week02/cmake-build-debug/CMakeFiles/49_UglyNumber.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/49_UglyNumber.dir/depend

