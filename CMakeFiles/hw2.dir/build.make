# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.8.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.8.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/matthewstewart/Documents/Junior Summer/cs148-student-repo"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/matthewstewart/Documents/Junior Summer/cs148-student-repo"

# Include any dependencies generated for this target.
include hws/hw2/CMakeFiles/hw2.dir/depend.make

# Include the progress variables for this target.
include hws/hw2/CMakeFiles/hw2.dir/progress.make

# Include the compile flags for this target's objects.
include hws/hw2/CMakeFiles/hw2.dir/flags.make

hws/hw2/CMakeFiles/hw2.dir/main.cpp.o: hws/hw2/CMakeFiles/hw2.dir/flags.make
hws/hw2/CMakeFiles/hw2.dir/main.cpp.o: hws/hw2/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/matthewstewart/Documents/Junior Summer/cs148-student-repo/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object hws/hw2/CMakeFiles/hw2.dir/main.cpp.o"
	cd "/Users/matthewstewart/Documents/Junior Summer/cs148-student-repo/hws/hw2" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw2.dir/main.cpp.o -c "/Users/matthewstewart/Documents/Junior Summer/cs148-student-repo/hws/hw2/main.cpp"

hws/hw2/CMakeFiles/hw2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw2.dir/main.cpp.i"
	cd "/Users/matthewstewart/Documents/Junior Summer/cs148-student-repo/hws/hw2" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/matthewstewart/Documents/Junior Summer/cs148-student-repo/hws/hw2/main.cpp" > CMakeFiles/hw2.dir/main.cpp.i

hws/hw2/CMakeFiles/hw2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw2.dir/main.cpp.s"
	cd "/Users/matthewstewart/Documents/Junior Summer/cs148-student-repo/hws/hw2" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/matthewstewart/Documents/Junior Summer/cs148-student-repo/hws/hw2/main.cpp" -o CMakeFiles/hw2.dir/main.cpp.s

hws/hw2/CMakeFiles/hw2.dir/main.cpp.o.requires:

.PHONY : hws/hw2/CMakeFiles/hw2.dir/main.cpp.o.requires

hws/hw2/CMakeFiles/hw2.dir/main.cpp.o.provides: hws/hw2/CMakeFiles/hw2.dir/main.cpp.o.requires
	$(MAKE) -f hws/hw2/CMakeFiles/hw2.dir/build.make hws/hw2/CMakeFiles/hw2.dir/main.cpp.o.provides.build
.PHONY : hws/hw2/CMakeFiles/hw2.dir/main.cpp.o.provides

hws/hw2/CMakeFiles/hw2.dir/main.cpp.o.provides.build: hws/hw2/CMakeFiles/hw2.dir/main.cpp.o


# Object files for target hw2
hw2_OBJECTS = \
"CMakeFiles/hw2.dir/main.cpp.o"

# External object files for target hw2
hw2_EXTERNAL_OBJECTS =

bin/hw2: hws/hw2/CMakeFiles/hw2.dir/main.cpp.o
bin/hw2: hws/hw2/CMakeFiles/hw2.dir/build.make
bin/hw2: lib/libhw2.a
bin/hw2: lib/libglew.a
bin/hw2: lib/libglfw3.a
bin/hw2: hws/hw2/CMakeFiles/hw2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/matthewstewart/Documents/Junior Summer/cs148-student-repo/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/hw2"
	cd "/Users/matthewstewart/Documents/Junior Summer/cs148-student-repo/hws/hw2" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hw2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
hws/hw2/CMakeFiles/hw2.dir/build: bin/hw2

.PHONY : hws/hw2/CMakeFiles/hw2.dir/build

hws/hw2/CMakeFiles/hw2.dir/requires: hws/hw2/CMakeFiles/hw2.dir/main.cpp.o.requires

.PHONY : hws/hw2/CMakeFiles/hw2.dir/requires

hws/hw2/CMakeFiles/hw2.dir/clean:
	cd "/Users/matthewstewart/Documents/Junior Summer/cs148-student-repo/hws/hw2" && $(CMAKE_COMMAND) -P CMakeFiles/hw2.dir/cmake_clean.cmake
.PHONY : hws/hw2/CMakeFiles/hw2.dir/clean

hws/hw2/CMakeFiles/hw2.dir/depend:
	cd "/Users/matthewstewart/Documents/Junior Summer/cs148-student-repo" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/matthewstewart/Documents/Junior Summer/cs148-student-repo" "/Users/matthewstewart/Documents/Junior Summer/cs148-student-repo/hws/hw2" "/Users/matthewstewart/Documents/Junior Summer/cs148-student-repo" "/Users/matthewstewart/Documents/Junior Summer/cs148-student-repo/hws/hw2" "/Users/matthewstewart/Documents/Junior Summer/cs148-student-repo/hws/hw2/CMakeFiles/hw2.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : hws/hw2/CMakeFiles/hw2.dir/depend
