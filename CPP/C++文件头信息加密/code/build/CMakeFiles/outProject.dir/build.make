# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = D:\dev\cmake-3.19.0-rc3-win64-x64\bin\cmake.exe

# The command to remove a file.
RM = D:\dev\cmake-3.19.0-rc3-win64-x64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\dev\WORKSPACE\C_C++\2018.08\project2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\dev\WORKSPACE\C_C++\2018.08\project2\build

# Include any dependencies generated for this target.
include CMakeFiles/outProject.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/outProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/outProject.dir/flags.make

CMakeFiles/outProject.dir/009FileRead/binWrite03.cpp.obj: CMakeFiles/outProject.dir/flags.make
CMakeFiles/outProject.dir/009FileRead/binWrite03.cpp.obj: CMakeFiles/outProject.dir/includes_CXX.rsp
CMakeFiles/outProject.dir/009FileRead/binWrite03.cpp.obj: ../009FileRead/binWrite03.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\dev\WORKSPACE\C_C++\2018.08\project2\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/outProject.dir/009FileRead/binWrite03.cpp.obj"
	D:\dev\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\outProject.dir\009FileRead\binWrite03.cpp.obj -c D:\dev\WORKSPACE\C_C++\2018.08\project2\009FileRead\binWrite03.cpp

CMakeFiles/outProject.dir/009FileRead/binWrite03.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/outProject.dir/009FileRead/binWrite03.cpp.i"
	D:\dev\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\dev\WORKSPACE\C_C++\2018.08\project2\009FileRead\binWrite03.cpp > CMakeFiles\outProject.dir\009FileRead\binWrite03.cpp.i

CMakeFiles/outProject.dir/009FileRead/binWrite03.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/outProject.dir/009FileRead/binWrite03.cpp.s"
	D:\dev\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\dev\WORKSPACE\C_C++\2018.08\project2\009FileRead\binWrite03.cpp -o CMakeFiles\outProject.dir\009FileRead\binWrite03.cpp.s

# Object files for target outProject
outProject_OBJECTS = \
"CMakeFiles/outProject.dir/009FileRead/binWrite03.cpp.obj"

# External object files for target outProject
outProject_EXTERNAL_OBJECTS =

outProject.exe: CMakeFiles/outProject.dir/009FileRead/binWrite03.cpp.obj
outProject.exe: CMakeFiles/outProject.dir/build.make
outProject.exe: D:/dev/anaconda3/Library/lib/libcrypto.lib
outProject.exe: CMakeFiles/outProject.dir/linklibs.rsp
outProject.exe: CMakeFiles/outProject.dir/objects1.rsp
outProject.exe: CMakeFiles/outProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\dev\WORKSPACE\C_C++\2018.08\project2\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable outProject.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\outProject.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/outProject.dir/build: outProject.exe

.PHONY : CMakeFiles/outProject.dir/build

CMakeFiles/outProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\outProject.dir\cmake_clean.cmake
.PHONY : CMakeFiles/outProject.dir/clean

CMakeFiles/outProject.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\dev\WORKSPACE\C_C++\2018.08\project2 D:\dev\WORKSPACE\C_C++\2018.08\project2 D:\dev\WORKSPACE\C_C++\2018.08\project2\build D:\dev\WORKSPACE\C_C++\2018.08\project2\build D:\dev\WORKSPACE\C_C++\2018.08\project2\build\CMakeFiles\outProject.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/outProject.dir/depend

