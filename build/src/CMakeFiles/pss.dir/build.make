# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/jin/Desktop/testGraph (2)"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/jin/Desktop/testGraph (2)/build"

# Include any dependencies generated for this target.
include src/CMakeFiles/pss.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/pss.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/pss.dir/flags.make

src/CMakeFiles/pss.dir/pss.cpp.o: src/CMakeFiles/pss.dir/flags.make
src/CMakeFiles/pss.dir/pss.cpp.o: ../src/pss.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/jin/Desktop/testGraph (2)/build/CMakeFiles" $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/pss.dir/pss.cpp.o"
	cd "/home/jin/Desktop/testGraph (2)/build/src" && g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/pss.dir/pss.cpp.o -c "/home/jin/Desktop/testGraph (2)/src/pss.cpp"

src/CMakeFiles/pss.dir/pss.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pss.dir/pss.cpp.i"
	cd "/home/jin/Desktop/testGraph (2)/build/src" && g++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/jin/Desktop/testGraph (2)/src/pss.cpp" > CMakeFiles/pss.dir/pss.cpp.i

src/CMakeFiles/pss.dir/pss.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pss.dir/pss.cpp.s"
	cd "/home/jin/Desktop/testGraph (2)/build/src" && g++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/jin/Desktop/testGraph (2)/src/pss.cpp" -o CMakeFiles/pss.dir/pss.cpp.s

src/CMakeFiles/pss.dir/pss.cpp.o.requires:
.PHONY : src/CMakeFiles/pss.dir/pss.cpp.o.requires

src/CMakeFiles/pss.dir/pss.cpp.o.provides: src/CMakeFiles/pss.dir/pss.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/pss.dir/build.make src/CMakeFiles/pss.dir/pss.cpp.o.provides.build
.PHONY : src/CMakeFiles/pss.dir/pss.cpp.o.provides

src/CMakeFiles/pss.dir/pss.cpp.o.provides.build: src/CMakeFiles/pss.dir/pss.cpp.o

# Object files for target pss
pss_OBJECTS = \
"CMakeFiles/pss.dir/pss.cpp.o"

# External object files for target pss
pss_EXTERNAL_OBJECTS =

../bin/pss: src/CMakeFiles/pss.dir/pss.cpp.o
../bin/pss: src/CMakeFiles/pss.dir/build.make
../bin/pss: src/CMakeFiles/pss.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../bin/pss"
	cd "/home/jin/Desktop/testGraph (2)/build/src" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pss.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/pss.dir/build: ../bin/pss
.PHONY : src/CMakeFiles/pss.dir/build

src/CMakeFiles/pss.dir/requires: src/CMakeFiles/pss.dir/pss.cpp.o.requires
.PHONY : src/CMakeFiles/pss.dir/requires

src/CMakeFiles/pss.dir/clean:
	cd "/home/jin/Desktop/testGraph (2)/build/src" && $(CMAKE_COMMAND) -P CMakeFiles/pss.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/pss.dir/clean

src/CMakeFiles/pss.dir/depend:
	cd "/home/jin/Desktop/testGraph (2)/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/jin/Desktop/testGraph (2)" "/home/jin/Desktop/testGraph (2)/src" "/home/jin/Desktop/testGraph (2)/build" "/home/jin/Desktop/testGraph (2)/build/src" "/home/jin/Desktop/testGraph (2)/build/src/CMakeFiles/pss.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : src/CMakeFiles/pss.dir/depend

