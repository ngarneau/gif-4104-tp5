# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/eymeric/prog/gif-4104-tp5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/eymeric/prog/gif-4104-tp5/build

# Include any dependencies generated for this target.
include CMakeFiles/test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test.dir/flags.make

CMakeFiles/test.dir/test.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/test.cpp.o: ../test.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/eymeric/prog/gif-4104-tp5/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/test.dir/test.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test.dir/test.cpp.o -c /home/eymeric/prog/gif-4104-tp5/test.cpp

CMakeFiles/test.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/test.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/eymeric/prog/gif-4104-tp5/test.cpp > CMakeFiles/test.dir/test.cpp.i

CMakeFiles/test.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/test.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/eymeric/prog/gif-4104-tp5/test.cpp -o CMakeFiles/test.dir/test.cpp.s

CMakeFiles/test.dir/test.cpp.o.requires:
.PHONY : CMakeFiles/test.dir/test.cpp.o.requires

CMakeFiles/test.dir/test.cpp.o.provides: CMakeFiles/test.dir/test.cpp.o.requires
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/test.cpp.o.provides.build
.PHONY : CMakeFiles/test.dir/test.cpp.o.provides

CMakeFiles/test.dir/test.cpp.o.provides.build: CMakeFiles/test.dir/test.cpp.o

CMakeFiles/test.dir/util/Square.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/util/Square.cpp.o: ../util/Square.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/eymeric/prog/gif-4104-tp5/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/test.dir/util/Square.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test.dir/util/Square.cpp.o -c /home/eymeric/prog/gif-4104-tp5/util/Square.cpp

CMakeFiles/test.dir/util/Square.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/util/Square.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/eymeric/prog/gif-4104-tp5/util/Square.cpp > CMakeFiles/test.dir/util/Square.cpp.i

CMakeFiles/test.dir/util/Square.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/util/Square.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/eymeric/prog/gif-4104-tp5/util/Square.cpp -o CMakeFiles/test.dir/util/Square.cpp.s

CMakeFiles/test.dir/util/Square.cpp.o.requires:
.PHONY : CMakeFiles/test.dir/util/Square.cpp.o.requires

CMakeFiles/test.dir/util/Square.cpp.o.provides: CMakeFiles/test.dir/util/Square.cpp.o.requires
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/util/Square.cpp.o.provides.build
.PHONY : CMakeFiles/test.dir/util/Square.cpp.o.provides

CMakeFiles/test.dir/util/Square.cpp.o.provides.build: CMakeFiles/test.dir/util/Square.cpp.o

CMakeFiles/test.dir/util/Game.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/util/Game.cpp.o: ../util/Game.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/eymeric/prog/gif-4104-tp5/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/test.dir/util/Game.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test.dir/util/Game.cpp.o -c /home/eymeric/prog/gif-4104-tp5/util/Game.cpp

CMakeFiles/test.dir/util/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/util/Game.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/eymeric/prog/gif-4104-tp5/util/Game.cpp > CMakeFiles/test.dir/util/Game.cpp.i

CMakeFiles/test.dir/util/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/util/Game.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/eymeric/prog/gif-4104-tp5/util/Game.cpp -o CMakeFiles/test.dir/util/Game.cpp.s

CMakeFiles/test.dir/util/Game.cpp.o.requires:
.PHONY : CMakeFiles/test.dir/util/Game.cpp.o.requires

CMakeFiles/test.dir/util/Game.cpp.o.provides: CMakeFiles/test.dir/util/Game.cpp.o.requires
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/util/Game.cpp.o.provides.build
.PHONY : CMakeFiles/test.dir/util/Game.cpp.o.provides

CMakeFiles/test.dir/util/Game.cpp.o.provides.build: CMakeFiles/test.dir/util/Game.cpp.o

CMakeFiles/test.dir/util/Player.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/util/Player.cpp.o: ../util/Player.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/eymeric/prog/gif-4104-tp5/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/test.dir/util/Player.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test.dir/util/Player.cpp.o -c /home/eymeric/prog/gif-4104-tp5/util/Player.cpp

CMakeFiles/test.dir/util/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/util/Player.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/eymeric/prog/gif-4104-tp5/util/Player.cpp > CMakeFiles/test.dir/util/Player.cpp.i

CMakeFiles/test.dir/util/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/util/Player.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/eymeric/prog/gif-4104-tp5/util/Player.cpp -o CMakeFiles/test.dir/util/Player.cpp.s

CMakeFiles/test.dir/util/Player.cpp.o.requires:
.PHONY : CMakeFiles/test.dir/util/Player.cpp.o.requires

CMakeFiles/test.dir/util/Player.cpp.o.provides: CMakeFiles/test.dir/util/Player.cpp.o.requires
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/util/Player.cpp.o.provides.build
.PHONY : CMakeFiles/test.dir/util/Player.cpp.o.provides

CMakeFiles/test.dir/util/Player.cpp.o.provides.build: CMakeFiles/test.dir/util/Player.cpp.o

CMakeFiles/test.dir/util/Move.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/util/Move.cpp.o: ../util/Move.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/eymeric/prog/gif-4104-tp5/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/test.dir/util/Move.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test.dir/util/Move.cpp.o -c /home/eymeric/prog/gif-4104-tp5/util/Move.cpp

CMakeFiles/test.dir/util/Move.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/util/Move.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/eymeric/prog/gif-4104-tp5/util/Move.cpp > CMakeFiles/test.dir/util/Move.cpp.i

CMakeFiles/test.dir/util/Move.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/util/Move.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/eymeric/prog/gif-4104-tp5/util/Move.cpp -o CMakeFiles/test.dir/util/Move.cpp.s

CMakeFiles/test.dir/util/Move.cpp.o.requires:
.PHONY : CMakeFiles/test.dir/util/Move.cpp.o.requires

CMakeFiles/test.dir/util/Move.cpp.o.provides: CMakeFiles/test.dir/util/Move.cpp.o.requires
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/util/Move.cpp.o.provides.build
.PHONY : CMakeFiles/test.dir/util/Move.cpp.o.provides

CMakeFiles/test.dir/util/Move.cpp.o.provides.build: CMakeFiles/test.dir/util/Move.cpp.o

CMakeFiles/test.dir/ai/Evaluator.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/ai/Evaluator.cpp.o: ../ai/Evaluator.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/eymeric/prog/gif-4104-tp5/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/test.dir/ai/Evaluator.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test.dir/ai/Evaluator.cpp.o -c /home/eymeric/prog/gif-4104-tp5/ai/Evaluator.cpp

CMakeFiles/test.dir/ai/Evaluator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/ai/Evaluator.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/eymeric/prog/gif-4104-tp5/ai/Evaluator.cpp > CMakeFiles/test.dir/ai/Evaluator.cpp.i

CMakeFiles/test.dir/ai/Evaluator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/ai/Evaluator.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/eymeric/prog/gif-4104-tp5/ai/Evaluator.cpp -o CMakeFiles/test.dir/ai/Evaluator.cpp.s

CMakeFiles/test.dir/ai/Evaluator.cpp.o.requires:
.PHONY : CMakeFiles/test.dir/ai/Evaluator.cpp.o.requires

CMakeFiles/test.dir/ai/Evaluator.cpp.o.provides: CMakeFiles/test.dir/ai/Evaluator.cpp.o.requires
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/ai/Evaluator.cpp.o.provides.build
.PHONY : CMakeFiles/test.dir/ai/Evaluator.cpp.o.provides

CMakeFiles/test.dir/ai/Evaluator.cpp.o.provides.build: CMakeFiles/test.dir/ai/Evaluator.cpp.o

CMakeFiles/test.dir/ai/AlphaBeta.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/ai/AlphaBeta.cpp.o: ../ai/AlphaBeta.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/eymeric/prog/gif-4104-tp5/build/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/test.dir/ai/AlphaBeta.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test.dir/ai/AlphaBeta.cpp.o -c /home/eymeric/prog/gif-4104-tp5/ai/AlphaBeta.cpp

CMakeFiles/test.dir/ai/AlphaBeta.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/ai/AlphaBeta.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/eymeric/prog/gif-4104-tp5/ai/AlphaBeta.cpp > CMakeFiles/test.dir/ai/AlphaBeta.cpp.i

CMakeFiles/test.dir/ai/AlphaBeta.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/ai/AlphaBeta.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/eymeric/prog/gif-4104-tp5/ai/AlphaBeta.cpp -o CMakeFiles/test.dir/ai/AlphaBeta.cpp.s

CMakeFiles/test.dir/ai/AlphaBeta.cpp.o.requires:
.PHONY : CMakeFiles/test.dir/ai/AlphaBeta.cpp.o.requires

CMakeFiles/test.dir/ai/AlphaBeta.cpp.o.provides: CMakeFiles/test.dir/ai/AlphaBeta.cpp.o.requires
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/ai/AlphaBeta.cpp.o.provides.build
.PHONY : CMakeFiles/test.dir/ai/AlphaBeta.cpp.o.provides

CMakeFiles/test.dir/ai/AlphaBeta.cpp.o.provides.build: CMakeFiles/test.dir/ai/AlphaBeta.cpp.o

CMakeFiles/test.dir/util/lodepng.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/util/lodepng.cpp.o: ../util/lodepng.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/eymeric/prog/gif-4104-tp5/build/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/test.dir/util/lodepng.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test.dir/util/lodepng.cpp.o -c /home/eymeric/prog/gif-4104-tp5/util/lodepng.cpp

CMakeFiles/test.dir/util/lodepng.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/util/lodepng.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/eymeric/prog/gif-4104-tp5/util/lodepng.cpp > CMakeFiles/test.dir/util/lodepng.cpp.i

CMakeFiles/test.dir/util/lodepng.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/util/lodepng.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/eymeric/prog/gif-4104-tp5/util/lodepng.cpp -o CMakeFiles/test.dir/util/lodepng.cpp.s

CMakeFiles/test.dir/util/lodepng.cpp.o.requires:
.PHONY : CMakeFiles/test.dir/util/lodepng.cpp.o.requires

CMakeFiles/test.dir/util/lodepng.cpp.o.provides: CMakeFiles/test.dir/util/lodepng.cpp.o.requires
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/util/lodepng.cpp.o.provides.build
.PHONY : CMakeFiles/test.dir/util/lodepng.cpp.o.provides

CMakeFiles/test.dir/util/lodepng.cpp.o.provides.build: CMakeFiles/test.dir/util/lodepng.cpp.o

# Object files for target test
test_OBJECTS = \
"CMakeFiles/test.dir/test.cpp.o" \
"CMakeFiles/test.dir/util/Square.cpp.o" \
"CMakeFiles/test.dir/util/Game.cpp.o" \
"CMakeFiles/test.dir/util/Player.cpp.o" \
"CMakeFiles/test.dir/util/Move.cpp.o" \
"CMakeFiles/test.dir/ai/Evaluator.cpp.o" \
"CMakeFiles/test.dir/ai/AlphaBeta.cpp.o" \
"CMakeFiles/test.dir/util/lodepng.cpp.o"

# External object files for target test
test_EXTERNAL_OBJECTS =

bin/test: CMakeFiles/test.dir/test.cpp.o
bin/test: CMakeFiles/test.dir/util/Square.cpp.o
bin/test: CMakeFiles/test.dir/util/Game.cpp.o
bin/test: CMakeFiles/test.dir/util/Player.cpp.o
bin/test: CMakeFiles/test.dir/util/Move.cpp.o
bin/test: CMakeFiles/test.dir/ai/Evaluator.cpp.o
bin/test: CMakeFiles/test.dir/ai/AlphaBeta.cpp.o
bin/test: CMakeFiles/test.dir/util/lodepng.cpp.o
bin/test: CMakeFiles/test.dir/build.make
bin/test: CMakeFiles/test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable bin/test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test.dir/build: bin/test
.PHONY : CMakeFiles/test.dir/build

CMakeFiles/test.dir/requires: CMakeFiles/test.dir/test.cpp.o.requires
CMakeFiles/test.dir/requires: CMakeFiles/test.dir/util/Square.cpp.o.requires
CMakeFiles/test.dir/requires: CMakeFiles/test.dir/util/Game.cpp.o.requires
CMakeFiles/test.dir/requires: CMakeFiles/test.dir/util/Player.cpp.o.requires
CMakeFiles/test.dir/requires: CMakeFiles/test.dir/util/Move.cpp.o.requires
CMakeFiles/test.dir/requires: CMakeFiles/test.dir/ai/Evaluator.cpp.o.requires
CMakeFiles/test.dir/requires: CMakeFiles/test.dir/ai/AlphaBeta.cpp.o.requires
CMakeFiles/test.dir/requires: CMakeFiles/test.dir/util/lodepng.cpp.o.requires
.PHONY : CMakeFiles/test.dir/requires

CMakeFiles/test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test.dir/clean

CMakeFiles/test.dir/depend:
	cd /home/eymeric/prog/gif-4104-tp5/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/eymeric/prog/gif-4104-tp5 /home/eymeric/prog/gif-4104-tp5 /home/eymeric/prog/gif-4104-tp5/build /home/eymeric/prog/gif-4104-tp5/build /home/eymeric/prog/gif-4104-tp5/build/CMakeFiles/test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test.dir/depend
