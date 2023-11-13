# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /home/arca/.local/lib/python3.8/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/arca/.local/lib/python3.8/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/d/CodeLibrary/oi/lab4/calculator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/CodeLibrary/oi/lab4/calculator

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "No interactive CMake dialog available..."
	/home/arca/.local/lib/python3.8/site-packages/cmake/data/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake to regenerate build system..."
	/home/arca/.local/lib/python3.8/site-packages/cmake/data/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /mnt/d/CodeLibrary/oi/lab4/calculator/CMakeFiles /mnt/d/CodeLibrary/oi/lab4/calculator//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /mnt/d/CodeLibrary/oi/lab4/calculator/CMakeFiles 0
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
# Target rules for targets named calc

# Build rule for target.
calc: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 calc
.PHONY : calc

# fast build rule for target.
calc/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/calc.dir/build.make CMakeFiles/calc.dir/build
.PHONY : calc/fast

char_operate.o: char_operate.c.o
.PHONY : char_operate.o

# target to build an object file
char_operate.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/calc.dir/build.make CMakeFiles/calc.dir/char_operate.c.o
.PHONY : char_operate.c.o

char_operate.i: char_operate.c.i
.PHONY : char_operate.i

# target to preprocess a source file
char_operate.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/calc.dir/build.make CMakeFiles/calc.dir/char_operate.c.i
.PHONY : char_operate.c.i

char_operate.s: char_operate.c.s
.PHONY : char_operate.s

# target to generate assembly for a file
char_operate.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/calc.dir/build.make CMakeFiles/calc.dir/char_operate.c.s
.PHONY : char_operate.c.s

expression_calc.o: expression_calc.c.o
.PHONY : expression_calc.o

# target to build an object file
expression_calc.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/calc.dir/build.make CMakeFiles/calc.dir/expression_calc.c.o
.PHONY : expression_calc.c.o

expression_calc.i: expression_calc.c.i
.PHONY : expression_calc.i

# target to preprocess a source file
expression_calc.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/calc.dir/build.make CMakeFiles/calc.dir/expression_calc.c.i
.PHONY : expression_calc.c.i

expression_calc.s: expression_calc.c.s
.PHONY : expression_calc.s

# target to generate assembly for a file
expression_calc.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/calc.dir/build.make CMakeFiles/calc.dir/expression_calc.c.s
.PHONY : expression_calc.c.s

main.o: main.c.o
.PHONY : main.o

# target to build an object file
main.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/calc.dir/build.make CMakeFiles/calc.dir/main.c.o
.PHONY : main.c.o

main.i: main.c.i
.PHONY : main.i

# target to preprocess a source file
main.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/calc.dir/build.make CMakeFiles/calc.dir/main.c.i
.PHONY : main.c.i

main.s: main.c.s
.PHONY : main.s

# target to generate assembly for a file
main.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/calc.dir/build.make CMakeFiles/calc.dir/main.c.s
.PHONY : main.c.s

stack.o: stack.c.o
.PHONY : stack.o

# target to build an object file
stack.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/calc.dir/build.make CMakeFiles/calc.dir/stack.c.o
.PHONY : stack.c.o

stack.i: stack.c.i
.PHONY : stack.i

# target to preprocess a source file
stack.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/calc.dir/build.make CMakeFiles/calc.dir/stack.c.i
.PHONY : stack.c.i

stack.s: stack.c.s
.PHONY : stack.s

# target to generate assembly for a file
stack.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/calc.dir/build.make CMakeFiles/calc.dir/stack.c.s
.PHONY : stack.c.s

string_process.o: string_process.c.o
.PHONY : string_process.o

# target to build an object file
string_process.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/calc.dir/build.make CMakeFiles/calc.dir/string_process.c.o
.PHONY : string_process.c.o

string_process.i: string_process.c.i
.PHONY : string_process.i

# target to preprocess a source file
string_process.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/calc.dir/build.make CMakeFiles/calc.dir/string_process.c.i
.PHONY : string_process.c.i

string_process.s: string_process.c.s
.PHONY : string_process.s

# target to generate assembly for a file
string_process.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/calc.dir/build.make CMakeFiles/calc.dir/string_process.c.s
.PHONY : string_process.c.s

utils.o: utils.c.o
.PHONY : utils.o

# target to build an object file
utils.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/calc.dir/build.make CMakeFiles/calc.dir/utils.c.o
.PHONY : utils.c.o

utils.i: utils.c.i
.PHONY : utils.i

# target to preprocess a source file
utils.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/calc.dir/build.make CMakeFiles/calc.dir/utils.c.i
.PHONY : utils.c.i

utils.s: utils.c.s
.PHONY : utils.s

# target to generate assembly for a file
utils.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/calc.dir/build.make CMakeFiles/calc.dir/utils.c.s
.PHONY : utils.c.s

var_system.o: var_system.c.o
.PHONY : var_system.o

# target to build an object file
var_system.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/calc.dir/build.make CMakeFiles/calc.dir/var_system.c.o
.PHONY : var_system.c.o

var_system.i: var_system.c.i
.PHONY : var_system.i

# target to preprocess a source file
var_system.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/calc.dir/build.make CMakeFiles/calc.dir/var_system.c.i
.PHONY : var_system.c.i

var_system.s: var_system.c.s
.PHONY : var_system.s

# target to generate assembly for a file
var_system.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/calc.dir/build.make CMakeFiles/calc.dir/var_system.c.s
.PHONY : var_system.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... calc"
	@echo "... char_operate.o"
	@echo "... char_operate.i"
	@echo "... char_operate.s"
	@echo "... expression_calc.o"
	@echo "... expression_calc.i"
	@echo "... expression_calc.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... stack.o"
	@echo "... stack.i"
	@echo "... stack.s"
	@echo "... string_process.o"
	@echo "... string_process.i"
	@echo "... string_process.s"
	@echo "... utils.o"
	@echo "... utils.i"
	@echo "... utils.s"
	@echo "... var_system.o"
	@echo "... var_system.i"
	@echo "... var_system.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
