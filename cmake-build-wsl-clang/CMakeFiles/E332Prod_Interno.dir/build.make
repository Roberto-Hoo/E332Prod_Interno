# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /mnt/s/Programacao/CParalelaUfrgs2020_2/cmake-3.20.1-linux-x86_64/bin/cmake

# The command to remove a file.
RM = /mnt/s/Programacao/CParalelaUfrgs2020_2/cmake-3.20.1-linux-x86_64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/s/Programacao/CParalelaUfrgs2020_2/E332Prod_Interno

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/s/Programacao/CParalelaUfrgs2020_2/E332Prod_Interno/cmake-build-wsl-clang

# Include any dependencies generated for this target.
include CMakeFiles/E332Prod_Interno.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/E332Prod_Interno.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/E332Prod_Interno.dir/flags.make

CMakeFiles/E332Prod_Interno.dir/E332Prod_Interno.cpp.o: CMakeFiles/E332Prod_Interno.dir/flags.make
CMakeFiles/E332Prod_Interno.dir/E332Prod_Interno.cpp.o: ../E332Prod_Interno.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/s/Programacao/CParalelaUfrgs2020_2/E332Prod_Interno/cmake-build-wsl-clang/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/E332Prod_Interno.dir/E332Prod_Interno.cpp.o"
	mpic++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/E332Prod_Interno.dir/E332Prod_Interno.cpp.o -c /mnt/s/Programacao/CParalelaUfrgs2020_2/E332Prod_Interno/E332Prod_Interno.cpp

CMakeFiles/E332Prod_Interno.dir/E332Prod_Interno.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/E332Prod_Interno.dir/E332Prod_Interno.cpp.i"
	mpic++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/s/Programacao/CParalelaUfrgs2020_2/E332Prod_Interno/E332Prod_Interno.cpp > CMakeFiles/E332Prod_Interno.dir/E332Prod_Interno.cpp.i

CMakeFiles/E332Prod_Interno.dir/E332Prod_Interno.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/E332Prod_Interno.dir/E332Prod_Interno.cpp.s"
	mpic++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/s/Programacao/CParalelaUfrgs2020_2/E332Prod_Interno/E332Prod_Interno.cpp -o CMakeFiles/E332Prod_Interno.dir/E332Prod_Interno.cpp.s

# Object files for target E332Prod_Interno
E332Prod_Interno_OBJECTS = \
"CMakeFiles/E332Prod_Interno.dir/E332Prod_Interno.cpp.o"

# External object files for target E332Prod_Interno
E332Prod_Interno_EXTERNAL_OBJECTS =

E332Prod_Interno: CMakeFiles/E332Prod_Interno.dir/E332Prod_Interno.cpp.o
E332Prod_Interno: CMakeFiles/E332Prod_Interno.dir/build.make
E332Prod_Interno: CMakeFiles/E332Prod_Interno.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/s/Programacao/CParalelaUfrgs2020_2/E332Prod_Interno/cmake-build-wsl-clang/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable E332Prod_Interno"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/E332Prod_Interno.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/E332Prod_Interno.dir/build: E332Prod_Interno
.PHONY : CMakeFiles/E332Prod_Interno.dir/build

CMakeFiles/E332Prod_Interno.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/E332Prod_Interno.dir/cmake_clean.cmake
.PHONY : CMakeFiles/E332Prod_Interno.dir/clean

CMakeFiles/E332Prod_Interno.dir/depend:
	cd /mnt/s/Programacao/CParalelaUfrgs2020_2/E332Prod_Interno/cmake-build-wsl-clang && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/s/Programacao/CParalelaUfrgs2020_2/E332Prod_Interno /mnt/s/Programacao/CParalelaUfrgs2020_2/E332Prod_Interno /mnt/s/Programacao/CParalelaUfrgs2020_2/E332Prod_Interno/cmake-build-wsl-clang /mnt/s/Programacao/CParalelaUfrgs2020_2/E332Prod_Interno/cmake-build-wsl-clang /mnt/s/Programacao/CParalelaUfrgs2020_2/E332Prod_Interno/cmake-build-wsl-clang/CMakeFiles/E332Prod_Interno.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/E332Prod_Interno.dir/depend

