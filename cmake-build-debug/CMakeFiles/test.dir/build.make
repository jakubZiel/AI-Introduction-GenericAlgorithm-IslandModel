# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /home/jakub/Apps/clion-2020.2.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/jakub/Apps/clion-2020.2.4/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /media/jakub/SDHC/sem5/PSZT/projekt/pszt-island-model

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/jakub/SDHC/sem5/PSZT/projekt/pszt-island-model/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test.dir/flags.make

CMakeFiles/test.dir/test/main.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/test/main.cpp.o: ../test/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/jakub/SDHC/sem5/PSZT/projekt/pszt-island-model/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test.dir/test/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test.dir/test/main.cpp.o -c /media/jakub/SDHC/sem5/PSZT/projekt/pszt-island-model/test/main.cpp

CMakeFiles/test.dir/test/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/test/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/jakub/SDHC/sem5/PSZT/projekt/pszt-island-model/test/main.cpp > CMakeFiles/test.dir/test/main.cpp.i

CMakeFiles/test.dir/test/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/test/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/jakub/SDHC/sem5/PSZT/projekt/pszt-island-model/test/main.cpp -o CMakeFiles/test.dir/test/main.cpp.s

CMakeFiles/test.dir/proto.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/proto.cpp.o: ../proto.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/jakub/SDHC/sem5/PSZT/projekt/pszt-island-model/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/test.dir/proto.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test.dir/proto.cpp.o -c /media/jakub/SDHC/sem5/PSZT/projekt/pszt-island-model/proto.cpp

CMakeFiles/test.dir/proto.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/proto.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/jakub/SDHC/sem5/PSZT/projekt/pszt-island-model/proto.cpp > CMakeFiles/test.dir/proto.cpp.i

CMakeFiles/test.dir/proto.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/proto.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/jakub/SDHC/sem5/PSZT/projekt/pszt-island-model/proto.cpp -o CMakeFiles/test.dir/proto.cpp.s

CMakeFiles/test.dir/structures/structures.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/structures/structures.cpp.o: ../structures/structures.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/jakub/SDHC/sem5/PSZT/projekt/pszt-island-model/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/test.dir/structures/structures.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test.dir/structures/structures.cpp.o -c /media/jakub/SDHC/sem5/PSZT/projekt/pszt-island-model/structures/structures.cpp

CMakeFiles/test.dir/structures/structures.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/structures/structures.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/jakub/SDHC/sem5/PSZT/projekt/pszt-island-model/structures/structures.cpp > CMakeFiles/test.dir/structures/structures.cpp.i

CMakeFiles/test.dir/structures/structures.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/structures/structures.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/jakub/SDHC/sem5/PSZT/projekt/pszt-island-model/structures/structures.cpp -o CMakeFiles/test.dir/structures/structures.cpp.s

CMakeFiles/test.dir/std-algorithm/evolutionary_operations.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/std-algorithm/evolutionary_operations.cpp.o: ../std-algorithm/evolutionary_operations.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/jakub/SDHC/sem5/PSZT/projekt/pszt-island-model/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/test.dir/std-algorithm/evolutionary_operations.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test.dir/std-algorithm/evolutionary_operations.cpp.o -c /media/jakub/SDHC/sem5/PSZT/projekt/pszt-island-model/std-algorithm/evolutionary_operations.cpp

CMakeFiles/test.dir/std-algorithm/evolutionary_operations.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/std-algorithm/evolutionary_operations.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/jakub/SDHC/sem5/PSZT/projekt/pszt-island-model/std-algorithm/evolutionary_operations.cpp > CMakeFiles/test.dir/std-algorithm/evolutionary_operations.cpp.i

CMakeFiles/test.dir/std-algorithm/evolutionary_operations.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/std-algorithm/evolutionary_operations.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/jakub/SDHC/sem5/PSZT/projekt/pszt-island-model/std-algorithm/evolutionary_operations.cpp -o CMakeFiles/test.dir/std-algorithm/evolutionary_operations.cpp.s

# Object files for target test
test_OBJECTS = \
"CMakeFiles/test.dir/test/main.cpp.o" \
"CMakeFiles/test.dir/proto.cpp.o" \
"CMakeFiles/test.dir/structures/structures.cpp.o" \
"CMakeFiles/test.dir/std-algorithm/evolutionary_operations.cpp.o"

# External object files for target test
test_EXTERNAL_OBJECTS =

test: CMakeFiles/test.dir/test/main.cpp.o
test: CMakeFiles/test.dir/proto.cpp.o
test: CMakeFiles/test.dir/structures/structures.cpp.o
test: CMakeFiles/test.dir/std-algorithm/evolutionary_operations.cpp.o
test: CMakeFiles/test.dir/build.make
test: CMakeFiles/test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/jakub/SDHC/sem5/PSZT/projekt/pszt-island-model/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test.dir/build: test

.PHONY : CMakeFiles/test.dir/build

CMakeFiles/test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test.dir/clean

CMakeFiles/test.dir/depend:
	cd /media/jakub/SDHC/sem5/PSZT/projekt/pszt-island-model/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/jakub/SDHC/sem5/PSZT/projekt/pszt-island-model /media/jakub/SDHC/sem5/PSZT/projekt/pszt-island-model /media/jakub/SDHC/sem5/PSZT/projekt/pszt-island-model/cmake-build-debug /media/jakub/SDHC/sem5/PSZT/projekt/pszt-island-model/cmake-build-debug /media/jakub/SDHC/sem5/PSZT/projekt/pszt-island-model/cmake-build-debug/CMakeFiles/test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test.dir/depend

