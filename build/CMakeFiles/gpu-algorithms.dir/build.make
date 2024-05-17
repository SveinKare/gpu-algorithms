# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\svein\gpu-algorithms

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\svein\gpu-algorithms\build

# Include any dependencies generated for this target.
include CMakeFiles/gpu-algorithms.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/gpu-algorithms.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/gpu-algorithms.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gpu-algorithms.dir/flags.make

CMakeFiles/gpu-algorithms.dir/main.cpp.obj: CMakeFiles/gpu-algorithms.dir/flags.make
CMakeFiles/gpu-algorithms.dir/main.cpp.obj: CMakeFiles/gpu-algorithms.dir/includes_CXX.rsp
CMakeFiles/gpu-algorithms.dir/main.cpp.obj: C:/Users/svein/gpu-algorithms/main.cpp
CMakeFiles/gpu-algorithms.dir/main.cpp.obj: CMakeFiles/gpu-algorithms.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\svein\gpu-algorithms\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gpu-algorithms.dir/main.cpp.obj"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gpu-algorithms.dir/main.cpp.obj -MF CMakeFiles\gpu-algorithms.dir\main.cpp.obj.d -o CMakeFiles\gpu-algorithms.dir\main.cpp.obj -c C:\Users\svein\gpu-algorithms\main.cpp

CMakeFiles/gpu-algorithms.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/gpu-algorithms.dir/main.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\svein\gpu-algorithms\main.cpp > CMakeFiles\gpu-algorithms.dir\main.cpp.i

CMakeFiles/gpu-algorithms.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/gpu-algorithms.dir/main.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\svein\gpu-algorithms\main.cpp -o CMakeFiles\gpu-algorithms.dir\main.cpp.s

# Object files for target gpu-algorithms
gpu__algorithms_OBJECTS = \
"CMakeFiles/gpu-algorithms.dir/main.cpp.obj"

# External object files for target gpu-algorithms
gpu__algorithms_EXTERNAL_OBJECTS =

gpu-algorithms.exe: CMakeFiles/gpu-algorithms.dir/main.cpp.obj
gpu-algorithms.exe: CMakeFiles/gpu-algorithms.dir/build.make
gpu-algorithms.exe: C:/Program\ Files/NVIDIA\ GPU\ Computing\ Toolkit/CUDA/v12.4/lib/x64/OpenCL.lib
gpu-algorithms.exe: CMakeFiles/gpu-algorithms.dir/linkLibs.rsp
gpu-algorithms.exe: CMakeFiles/gpu-algorithms.dir/objects1.rsp
gpu-algorithms.exe: CMakeFiles/gpu-algorithms.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\svein\gpu-algorithms\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable gpu-algorithms.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\gpu-algorithms.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gpu-algorithms.dir/build: gpu-algorithms.exe
.PHONY : CMakeFiles/gpu-algorithms.dir/build

CMakeFiles/gpu-algorithms.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\gpu-algorithms.dir\cmake_clean.cmake
.PHONY : CMakeFiles/gpu-algorithms.dir/clean

CMakeFiles/gpu-algorithms.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\svein\gpu-algorithms C:\Users\svein\gpu-algorithms C:\Users\svein\gpu-algorithms\build C:\Users\svein\gpu-algorithms\build C:\Users\svein\gpu-algorithms\build\CMakeFiles\gpu-algorithms.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/gpu-algorithms.dir/depend

