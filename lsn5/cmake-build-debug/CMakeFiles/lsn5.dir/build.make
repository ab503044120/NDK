# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/xiuchengyin/Documents/Tina-NDK/NDK/lsn5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/xiuchengyin/Documents/Tina-NDK/NDK/lsn5/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lsn5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lsn5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lsn5.dir/flags.make

CMakeFiles/lsn5.dir/lsn5.cpp.o: CMakeFiles/lsn5.dir/flags.make
CMakeFiles/lsn5.dir/lsn5.cpp.o: ../lsn5.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xiuchengyin/Documents/Tina-NDK/NDK/lsn5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lsn5.dir/lsn5.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lsn5.dir/lsn5.cpp.o -c /Users/xiuchengyin/Documents/Tina-NDK/NDK/lsn5/lsn5.cpp

CMakeFiles/lsn5.dir/lsn5.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lsn5.dir/lsn5.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/xiuchengyin/Documents/Tina-NDK/NDK/lsn5/lsn5.cpp > CMakeFiles/lsn5.dir/lsn5.cpp.i

CMakeFiles/lsn5.dir/lsn5.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lsn5.dir/lsn5.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/xiuchengyin/Documents/Tina-NDK/NDK/lsn5/lsn5.cpp -o CMakeFiles/lsn5.dir/lsn5.cpp.s

CMakeFiles/lsn5.dir/lsn5.cpp.o.requires:

.PHONY : CMakeFiles/lsn5.dir/lsn5.cpp.o.requires

CMakeFiles/lsn5.dir/lsn5.cpp.o.provides: CMakeFiles/lsn5.dir/lsn5.cpp.o.requires
	$(MAKE) -f CMakeFiles/lsn5.dir/build.make CMakeFiles/lsn5.dir/lsn5.cpp.o.provides.build
.PHONY : CMakeFiles/lsn5.dir/lsn5.cpp.o.provides

CMakeFiles/lsn5.dir/lsn5.cpp.o.provides.build: CMakeFiles/lsn5.dir/lsn5.cpp.o


# Object files for target lsn5
lsn5_OBJECTS = \
"CMakeFiles/lsn5.dir/lsn5.cpp.o"

# External object files for target lsn5
lsn5_EXTERNAL_OBJECTS =

lsn5: CMakeFiles/lsn5.dir/lsn5.cpp.o
lsn5: CMakeFiles/lsn5.dir/build.make
lsn5: CMakeFiles/lsn5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/xiuchengyin/Documents/Tina-NDK/NDK/lsn5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lsn5"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lsn5.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lsn5.dir/build: lsn5

.PHONY : CMakeFiles/lsn5.dir/build

CMakeFiles/lsn5.dir/requires: CMakeFiles/lsn5.dir/lsn5.cpp.o.requires

.PHONY : CMakeFiles/lsn5.dir/requires

CMakeFiles/lsn5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lsn5.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lsn5.dir/clean

CMakeFiles/lsn5.dir/depend:
	cd /Users/xiuchengyin/Documents/Tina-NDK/NDK/lsn5/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/xiuchengyin/Documents/Tina-NDK/NDK/lsn5 /Users/xiuchengyin/Documents/Tina-NDK/NDK/lsn5 /Users/xiuchengyin/Documents/Tina-NDK/NDK/lsn5/cmake-build-debug /Users/xiuchengyin/Documents/Tina-NDK/NDK/lsn5/cmake-build-debug /Users/xiuchengyin/Documents/Tina-NDK/NDK/lsn5/cmake-build-debug/CMakeFiles/lsn5.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lsn5.dir/depend

