# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/senny/sim

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/senny/sim/build

# Utility rule file for Simulation1.

# Include any custom commands dependencies for this target.
include CMakeFiles/Simulation1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Simulation1.dir/progress.make

CMakeFiles/Simulation1: sim1

Simulation1: CMakeFiles/Simulation1
Simulation1: CMakeFiles/Simulation1.dir/build.make
.PHONY : Simulation1

# Rule to build all files generated by this target.
CMakeFiles/Simulation1.dir/build: Simulation1
.PHONY : CMakeFiles/Simulation1.dir/build

CMakeFiles/Simulation1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Simulation1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Simulation1.dir/clean

CMakeFiles/Simulation1.dir/depend:
	cd /home/senny/sim/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/senny/sim /home/senny/sim /home/senny/sim/build /home/senny/sim/build /home/senny/sim/build/CMakeFiles/Simulation1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Simulation1.dir/depend
