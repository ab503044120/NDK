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
CMAKE_SOURCE_DIR = /Users/xiuchengyin/Documents/Tina-NDK/NDK/lsn4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/xiuchengyin/Documents/Tina-NDK/NDK/lsn4/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lsn4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lsn4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lsn4.dir/flags.make

CMakeFiles/lsn4.dir/main.cpp.o: CMakeFiles/lsn4.dir/flags.make
CMakeFiles/lsn4.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xiuchengyin/Documents/Tina-NDK/NDK/lsn4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lsn4.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lsn4.dir/main.cpp.o -c /Users/xiuchengyin/Documents/Tina-NDK/NDK/lsn4/main.cpp

CMakeFiles/lsn4.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lsn4.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/xiuchengyin/Documents/Tina-NDK/NDK/lsn4/main.cpp > CMakeFiles/lsn4.dir/main.cpp.i

CMakeFiles/lsn4.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lsn4.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/xiuchengyin/Documents/Tina-NDK/NDK/lsn4/main.cpp -o CMakeFiles/lsn4.dir/main.cpp.s

CMakeFiles/lsn4.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/lsn4.dir/main.cpp.o.requires

CMakeFiles/lsn4.dir/main.cpp.o.provides: CMakeFiles/lsn4.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/lsn4.dir/build.make CMakeFiles/lsn4.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/lsn4.dir/main.cpp.o.provides

CMakeFiles/lsn4.dir/main.cpp.o.provides.build: CMakeFiles/lsn4.dir/main.cpp.o


CMakeFiles/lsn4.dir/lsn4.cpp.o: CMakeFiles/lsn4.dir/flags.make
CMakeFiles/lsn4.dir/lsn4.cpp.o: ../lsn4.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xiuchengyin/Documents/Tina-NDK/NDK/lsn4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lsn4.dir/lsn4.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lsn4.dir/lsn4.cpp.o -c /Users/xiuchengyin/Documents/Tina-NDK/NDK/lsn4/lsn4.cpp

CMakeFiles/lsn4.dir/lsn4.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lsn4.dir/lsn4.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/xiuchengyin/Documents/Tina-NDK/NDK/lsn4/lsn4.cpp > CMakeFiles/lsn4.dir/lsn4.cpp.i

CMakeFiles/lsn4.dir/lsn4.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lsn4.dir/lsn4.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/xiuchengyin/Documents/Tina-NDK/NDK/lsn4/lsn4.cpp -o CMakeFiles/lsn4.dir/lsn4.cpp.s

CMakeFiles/lsn4.dir/lsn4.cpp.o.requires:

.PHONY : CMakeFiles/lsn4.dir/lsn4.cpp.o.requires

CMakeFiles/lsn4.dir/lsn4.cpp.o.provides: CMakeFiles/lsn4.dir/lsn4.cpp.o.requires
	$(MAKE) -f CMakeFiles/lsn4.dir/build.make CMakeFiles/lsn4.dir/lsn4.cpp.o.provides.build
.PHONY : CMakeFiles/lsn4.dir/lsn4.cpp.o.provides

CMakeFiles/lsn4.dir/lsn4.cpp.o.provides.build: CMakeFiles/lsn4.dir/lsn4.cpp.o


CMakeFiles/lsn4.dir/Student.cpp.o: CMakeFiles/lsn4.dir/flags.make
CMakeFiles/lsn4.dir/Student.cpp.o: ../Student.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xiuchengyin/Documents/Tina-NDK/NDK/lsn4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/lsn4.dir/Student.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lsn4.dir/Student.cpp.o -c /Users/xiuchengyin/Documents/Tina-NDK/NDK/lsn4/Student.cpp

CMakeFiles/lsn4.dir/Student.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lsn4.dir/Student.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/xiuchengyin/Documents/Tina-NDK/NDK/lsn4/Student.cpp > CMakeFiles/lsn4.dir/Student.cpp.i

CMakeFiles/lsn4.dir/Student.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lsn4.dir/Student.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/xiuchengyin/Documents/Tina-NDK/NDK/lsn4/Student.cpp -o CMakeFiles/lsn4.dir/Student.cpp.s

CMakeFiles/lsn4.dir/Student.cpp.o.requires:

.PHONY : CMakeFiles/lsn4.dir/Student.cpp.o.requires

CMakeFiles/lsn4.dir/Student.cpp.o.provides: CMakeFiles/lsn4.dir/Student.cpp.o.requires
	$(MAKE) -f CMakeFiles/lsn4.dir/build.make CMakeFiles/lsn4.dir/Student.cpp.o.provides.build
.PHONY : CMakeFiles/lsn4.dir/Student.cpp.o.provides

CMakeFiles/lsn4.dir/Student.cpp.o.provides.build: CMakeFiles/lsn4.dir/Student.cpp.o


# Object files for target lsn4
lsn4_OBJECTS = \
"CMakeFiles/lsn4.dir/main.cpp.o" \
"CMakeFiles/lsn4.dir/lsn4.cpp.o" \
"CMakeFiles/lsn4.dir/Student.cpp.o"

# External object files for target lsn4
lsn4_EXTERNAL_OBJECTS =

lsn4: CMakeFiles/lsn4.dir/main.cpp.o
lsn4: CMakeFiles/lsn4.dir/lsn4.cpp.o
lsn4: CMakeFiles/lsn4.dir/Student.cpp.o
lsn4: CMakeFiles/lsn4.dir/build.make
lsn4: CMakeFiles/lsn4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/xiuchengyin/Documents/Tina-NDK/NDK/lsn4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable lsn4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lsn4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lsn4.dir/build: lsn4

.PHONY : CMakeFiles/lsn4.dir/build

CMakeFiles/lsn4.dir/requires: CMakeFiles/lsn4.dir/main.cpp.o.requires
CMakeFiles/lsn4.dir/requires: CMakeFiles/lsn4.dir/lsn4.cpp.o.requires
CMakeFiles/lsn4.dir/requires: CMakeFiles/lsn4.dir/Student.cpp.o.requires

.PHONY : CMakeFiles/lsn4.dir/requires

CMakeFiles/lsn4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lsn4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lsn4.dir/clean

CMakeFiles/lsn4.dir/depend:
	cd /Users/xiuchengyin/Documents/Tina-NDK/NDK/lsn4/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/xiuchengyin/Documents/Tina-NDK/NDK/lsn4 /Users/xiuchengyin/Documents/Tina-NDK/NDK/lsn4 /Users/xiuchengyin/Documents/Tina-NDK/NDK/lsn4/cmake-build-debug /Users/xiuchengyin/Documents/Tina-NDK/NDK/lsn4/cmake-build-debug /Users/xiuchengyin/Documents/Tina-NDK/NDK/lsn4/cmake-build-debug/CMakeFiles/lsn4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lsn4.dir/depend

