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
CMAKE_SOURCE_DIR = /home/lewang/algorithm018/week08

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lewang/algorithm018/week08/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/bubble_sort_template.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/bubble_sort_template.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bubble_sort_template.dir/flags.make

CMakeFiles/bubble_sort_template.dir/bubble_sort_template.cpp.o: CMakeFiles/bubble_sort_template.dir/flags.make
CMakeFiles/bubble_sort_template.dir/bubble_sort_template.cpp.o: ../bubble_sort_template.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lewang/algorithm018/week08/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bubble_sort_template.dir/bubble_sort_template.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bubble_sort_template.dir/bubble_sort_template.cpp.o -c /home/lewang/algorithm018/week08/bubble_sort_template.cpp

CMakeFiles/bubble_sort_template.dir/bubble_sort_template.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bubble_sort_template.dir/bubble_sort_template.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lewang/algorithm018/week08/bubble_sort_template.cpp > CMakeFiles/bubble_sort_template.dir/bubble_sort_template.cpp.i

CMakeFiles/bubble_sort_template.dir/bubble_sort_template.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bubble_sort_template.dir/bubble_sort_template.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lewang/algorithm018/week08/bubble_sort_template.cpp -o CMakeFiles/bubble_sort_template.dir/bubble_sort_template.cpp.s

# Object files for target bubble_sort_template
bubble_sort_template_OBJECTS = \
"CMakeFiles/bubble_sort_template.dir/bubble_sort_template.cpp.o"

# External object files for target bubble_sort_template
bubble_sort_template_EXTERNAL_OBJECTS =

bubble_sort_template: CMakeFiles/bubble_sort_template.dir/bubble_sort_template.cpp.o
bubble_sort_template: CMakeFiles/bubble_sort_template.dir/build.make
bubble_sort_template: CMakeFiles/bubble_sort_template.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lewang/algorithm018/week08/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bubble_sort_template"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bubble_sort_template.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bubble_sort_template.dir/build: bubble_sort_template

.PHONY : CMakeFiles/bubble_sort_template.dir/build

CMakeFiles/bubble_sort_template.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bubble_sort_template.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bubble_sort_template.dir/clean

CMakeFiles/bubble_sort_template.dir/depend:
	cd /home/lewang/algorithm018/week08/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lewang/algorithm018/week08 /home/lewang/algorithm018/week08 /home/lewang/algorithm018/week08/cmake-build-debug /home/lewang/algorithm018/week08/cmake-build-debug /home/lewang/algorithm018/week08/cmake-build-debug/CMakeFiles/bubble_sort_template.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bubble_sort_template.dir/depend

