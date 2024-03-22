# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_SOURCE_DIR = /home/chipsy/FIT/IVS/ivs_project_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chipsy/FIT/IVS/ivs_project_1

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target test
test:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running tests..."
	/usr/bin/ctest --force-new-ctest-process $(ARGS)
.PHONY : test

# Special rule for the target test
test/fast: test
.PHONY : test/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components
.PHONY : list_install_components/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/chipsy/FIT/IVS/ivs_project_1/CMakeFiles /home/chipsy/FIT/IVS/ivs_project_1//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/chipsy/FIT/IVS/ivs_project_1/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named black_box_test

# Build rule for target.
black_box_test: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 black_box_test
.PHONY : black_box_test

# fast build rule for target.
black_box_test/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/black_box_test.dir/build.make CMakeFiles/black_box_test.dir/build
.PHONY : black_box_test/fast

#=============================================================================
# Target rules for targets named white_box_test

# Build rule for target.
white_box_test: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 white_box_test
.PHONY : white_box_test

# fast build rule for target.
white_box_test/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/white_box_test.dir/build.make CMakeFiles/white_box_test.dir/build
.PHONY : white_box_test/fast

#=============================================================================
# Target rules for targets named white_box_test_coverage

# Build rule for target.
white_box_test_coverage: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 white_box_test_coverage
.PHONY : white_box_test_coverage

# fast build rule for target.
white_box_test_coverage/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/white_box_test_coverage.dir/build.make CMakeFiles/white_box_test_coverage.dir/build
.PHONY : white_box_test_coverage/fast

#=============================================================================
# Target rules for targets named tdd_test

# Build rule for target.
tdd_test: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 tdd_test
.PHONY : tdd_test

# fast build rule for target.
tdd_test/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/tdd_test.dir/build.make CMakeFiles/tdd_test.dir/build
.PHONY : tdd_test/fast

#=============================================================================
# Target rules for targets named tdd_test_coverage

# Build rule for target.
tdd_test_coverage: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 tdd_test_coverage
.PHONY : tdd_test_coverage

# fast build rule for target.
tdd_test_coverage/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/tdd_test_coverage.dir/build.make CMakeFiles/tdd_test_coverage.dir/build
.PHONY : tdd_test_coverage/fast

#=============================================================================
# Target rules for targets named pack

# Build rule for target.
pack: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 pack
.PHONY : pack

# fast build rule for target.
pack/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pack.dir/build.make CMakeFiles/pack.dir/build
.PHONY : pack/fast

#=============================================================================
# Target rules for targets named gmock

# Build rule for target.
gmock: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 gmock
.PHONY : gmock

# fast build rule for target.
gmock/fast:
	$(MAKE) $(MAKESILENT) -f _deps/googletest-build/googlemock/CMakeFiles/gmock.dir/build.make _deps/googletest-build/googlemock/CMakeFiles/gmock.dir/build
.PHONY : gmock/fast

#=============================================================================
# Target rules for targets named gmock_main

# Build rule for target.
gmock_main: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 gmock_main
.PHONY : gmock_main

# fast build rule for target.
gmock_main/fast:
	$(MAKE) $(MAKESILENT) -f _deps/googletest-build/googlemock/CMakeFiles/gmock_main.dir/build.make _deps/googletest-build/googlemock/CMakeFiles/gmock_main.dir/build
.PHONY : gmock_main/fast

#=============================================================================
# Target rules for targets named gtest

# Build rule for target.
gtest: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 gtest
.PHONY : gtest

# fast build rule for target.
gtest/fast:
	$(MAKE) $(MAKESILENT) -f _deps/googletest-build/googletest/CMakeFiles/gtest.dir/build.make _deps/googletest-build/googletest/CMakeFiles/gtest.dir/build
.PHONY : gtest/fast

#=============================================================================
# Target rules for targets named gtest_main

# Build rule for target.
gtest_main: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 gtest_main
.PHONY : gtest_main

# fast build rule for target.
gtest_main/fast:
	$(MAKE) $(MAKESILENT) -f _deps/googletest-build/googletest/CMakeFiles/gtest_main.dir/build.make _deps/googletest-build/googletest/CMakeFiles/gtest_main.dir/build
.PHONY : gtest_main/fast

black_box_tests.o: black_box_tests.cpp.o
.PHONY : black_box_tests.o

# target to build an object file
black_box_tests.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/black_box_test.dir/build.make CMakeFiles/black_box_test.dir/black_box_tests.cpp.o
.PHONY : black_box_tests.cpp.o

black_box_tests.i: black_box_tests.cpp.i
.PHONY : black_box_tests.i

# target to preprocess a source file
black_box_tests.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/black_box_test.dir/build.make CMakeFiles/black_box_test.dir/black_box_tests.cpp.i
.PHONY : black_box_tests.cpp.i

black_box_tests.s: black_box_tests.cpp.s
.PHONY : black_box_tests.s

# target to generate assembly for a file
black_box_tests.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/black_box_test.dir/build.make CMakeFiles/black_box_test.dir/black_box_tests.cpp.s
.PHONY : black_box_tests.cpp.s

tdd_code.o: tdd_code.cpp.o
.PHONY : tdd_code.o

# target to build an object file
tdd_code.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/tdd_test.dir/build.make CMakeFiles/tdd_test.dir/tdd_code.cpp.o
.PHONY : tdd_code.cpp.o

tdd_code.i: tdd_code.cpp.i
.PHONY : tdd_code.i

# target to preprocess a source file
tdd_code.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/tdd_test.dir/build.make CMakeFiles/tdd_test.dir/tdd_code.cpp.i
.PHONY : tdd_code.cpp.i

tdd_code.s: tdd_code.cpp.s
.PHONY : tdd_code.s

# target to generate assembly for a file
tdd_code.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/tdd_test.dir/build.make CMakeFiles/tdd_test.dir/tdd_code.cpp.s
.PHONY : tdd_code.cpp.s

tdd_tests.o: tdd_tests.cpp.o
.PHONY : tdd_tests.o

# target to build an object file
tdd_tests.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/tdd_test.dir/build.make CMakeFiles/tdd_test.dir/tdd_tests.cpp.o
.PHONY : tdd_tests.cpp.o

tdd_tests.i: tdd_tests.cpp.i
.PHONY : tdd_tests.i

# target to preprocess a source file
tdd_tests.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/tdd_test.dir/build.make CMakeFiles/tdd_test.dir/tdd_tests.cpp.i
.PHONY : tdd_tests.cpp.i

tdd_tests.s: tdd_tests.cpp.s
.PHONY : tdd_tests.s

# target to generate assembly for a file
tdd_tests.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/tdd_test.dir/build.make CMakeFiles/tdd_test.dir/tdd_tests.cpp.s
.PHONY : tdd_tests.cpp.s

white_box_code.o: white_box_code.cpp.o
.PHONY : white_box_code.o

# target to build an object file
white_box_code.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/white_box_test.dir/build.make CMakeFiles/white_box_test.dir/white_box_code.cpp.o
.PHONY : white_box_code.cpp.o

white_box_code.i: white_box_code.cpp.i
.PHONY : white_box_code.i

# target to preprocess a source file
white_box_code.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/white_box_test.dir/build.make CMakeFiles/white_box_test.dir/white_box_code.cpp.i
.PHONY : white_box_code.cpp.i

white_box_code.s: white_box_code.cpp.s
.PHONY : white_box_code.s

# target to generate assembly for a file
white_box_code.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/white_box_test.dir/build.make CMakeFiles/white_box_test.dir/white_box_code.cpp.s
.PHONY : white_box_code.cpp.s

white_box_tests.o: white_box_tests.cpp.o
.PHONY : white_box_tests.o

# target to build an object file
white_box_tests.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/white_box_test.dir/build.make CMakeFiles/white_box_test.dir/white_box_tests.cpp.o
.PHONY : white_box_tests.cpp.o

white_box_tests.i: white_box_tests.cpp.i
.PHONY : white_box_tests.i

# target to preprocess a source file
white_box_tests.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/white_box_test.dir/build.make CMakeFiles/white_box_test.dir/white_box_tests.cpp.i
.PHONY : white_box_tests.cpp.i

white_box_tests.s: white_box_tests.cpp.s
.PHONY : white_box_tests.s

# target to generate assembly for a file
white_box_tests.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/white_box_test.dir/build.make CMakeFiles/white_box_test.dir/white_box_tests.cpp.s
.PHONY : white_box_tests.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... install"
	@echo "... install/local"
	@echo "... install/strip"
	@echo "... list_install_components"
	@echo "... rebuild_cache"
	@echo "... test"
	@echo "... pack"
	@echo "... tdd_test_coverage"
	@echo "... white_box_test_coverage"
	@echo "... black_box_test"
	@echo "... gmock"
	@echo "... gmock_main"
	@echo "... gtest"
	@echo "... gtest_main"
	@echo "... tdd_test"
	@echo "... white_box_test"
	@echo "... black_box_tests.o"
	@echo "... black_box_tests.i"
	@echo "... black_box_tests.s"
	@echo "... tdd_code.o"
	@echo "... tdd_code.i"
	@echo "... tdd_code.s"
	@echo "... tdd_tests.o"
	@echo "... tdd_tests.i"
	@echo "... tdd_tests.s"
	@echo "... white_box_code.o"
	@echo "... white_box_code.i"
	@echo "... white_box_code.s"
	@echo "... white_box_tests.o"
	@echo "... white_box_tests.i"
	@echo "... white_box_tests.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

