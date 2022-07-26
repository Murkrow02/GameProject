# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/murkrow/Repos/GameProject/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/murkrow/Repos/GameProject

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
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

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/murkrow/Repos/GameProject/CMakeFiles /home/murkrow/Repos/GameProject//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/murkrow/Repos/GameProject/CMakeFiles 0
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
# Target rules for targets named GameProject2

# Build rule for target.
GameProject2: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 GameProject2
.PHONY : GameProject2

# fast build rule for target.
GameProject2/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/build
.PHONY : GameProject2/fast

Entities/player.o: Entities/player.cpp.o
.PHONY : Entities/player.o

# target to build an object file
Entities/player.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Entities/player.cpp.o
.PHONY : Entities/player.cpp.o

Entities/player.i: Entities/player.cpp.i
.PHONY : Entities/player.i

# target to preprocess a source file
Entities/player.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Entities/player.cpp.i
.PHONY : Entities/player.cpp.i

Entities/player.s: Entities/player.cpp.s
.PHONY : Entities/player.s

# target to generate assembly for a file
Entities/player.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Entities/player.cpp.s
.PHONY : Entities/player.cpp.s

Tools/savedata.o: Tools/savedata.cpp.o
.PHONY : Tools/savedata.o

# target to build an object file
Tools/savedata.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Tools/savedata.cpp.o
.PHONY : Tools/savedata.cpp.o

Tools/savedata.i: Tools/savedata.cpp.i
.PHONY : Tools/savedata.i

# target to preprocess a source file
Tools/savedata.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Tools/savedata.cpp.i
.PHONY : Tools/savedata.cpp.i

Tools/savedata.s: Tools/savedata.cpp.s
.PHONY : Tools/savedata.s

# target to generate assembly for a file
Tools/savedata.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Tools/savedata.cpp.s
.PHONY : Tools/savedata.cpp.s

Tools/utils.o: Tools/utils.cpp.o
.PHONY : Tools/utils.o

# target to build an object file
Tools/utils.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Tools/utils.cpp.o
.PHONY : Tools/utils.cpp.o

Tools/utils.i: Tools/utils.cpp.i
.PHONY : Tools/utils.i

# target to preprocess a source file
Tools/utils.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Tools/utils.cpp.i
.PHONY : Tools/utils.cpp.i

Tools/utils.s: Tools/utils.cpp.s
.PHONY : Tools/utils.s

# target to generate assembly for a file
Tools/utils.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Tools/utils.cpp.s
.PHONY : Tools/utils.cpp.s

UI/alert.o: UI/alert.cpp.o
.PHONY : UI/alert.o

# target to build an object file
UI/alert.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/UI/alert.cpp.o
.PHONY : UI/alert.cpp.o

UI/alert.i: UI/alert.cpp.i
.PHONY : UI/alert.i

# target to preprocess a source file
UI/alert.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/UI/alert.cpp.i
.PHONY : UI/alert.cpp.i

UI/alert.s: UI/alert.cpp.s
.PHONY : UI/alert.s

# target to generate assembly for a file
UI/alert.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/UI/alert.cpp.s
.PHONY : UI/alert.cpp.s

UI/dialog.o: UI/dialog.cpp.o
.PHONY : UI/dialog.o

# target to build an object file
UI/dialog.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/UI/dialog.cpp.o
.PHONY : UI/dialog.cpp.o

UI/dialog.i: UI/dialog.cpp.i
.PHONY : UI/dialog.i

# target to preprocess a source file
UI/dialog.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/UI/dialog.cpp.i
.PHONY : UI/dialog.cpp.i

UI/dialog.s: UI/dialog.cpp.s
.PHONY : UI/dialog.s

# target to generate assembly for a file
UI/dialog.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/UI/dialog.cpp.s
.PHONY : UI/dialog.cpp.s

UI/menu.o: UI/menu.cpp.o
.PHONY : UI/menu.o

# target to build an object file
UI/menu.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/UI/menu.cpp.o
.PHONY : UI/menu.cpp.o

UI/menu.i: UI/menu.cpp.i
.PHONY : UI/menu.i

# target to preprocess a source file
UI/menu.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/UI/menu.cpp.i
.PHONY : UI/menu.cpp.i

UI/menu.s: UI/menu.cpp.s
.PHONY : UI/menu.s

# target to generate assembly for a file
UI/menu.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/UI/menu.cpp.s
.PHONY : UI/menu.cpp.s

UI/message.o: UI/message.cpp.o
.PHONY : UI/message.o

# target to build an object file
UI/message.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/UI/message.cpp.o
.PHONY : UI/message.cpp.o

UI/message.i: UI/message.cpp.i
.PHONY : UI/message.i

# target to preprocess a source file
UI/message.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/UI/message.cpp.i
.PHONY : UI/message.cpp.i

UI/message.s: UI/message.cpp.s
.PHONY : UI/message.s

# target to generate assembly for a file
UI/message.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/UI/message.cpp.s
.PHONY : UI/message.cpp.s

UI/puzzle.o: UI/puzzle.cpp.o
.PHONY : UI/puzzle.o

# target to build an object file
UI/puzzle.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/UI/puzzle.cpp.o
.PHONY : UI/puzzle.cpp.o

UI/puzzle.i: UI/puzzle.cpp.i
.PHONY : UI/puzzle.i

# target to preprocess a source file
UI/puzzle.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/UI/puzzle.cpp.i
.PHONY : UI/puzzle.cpp.i

UI/puzzle.s: UI/puzzle.cpp.s
.PHONY : UI/puzzle.s

# target to generate assembly for a file
UI/puzzle.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/UI/puzzle.cpp.s
.PHONY : UI/puzzle.cpp.s

main.o: main.cpp.o
.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i
.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s
.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/main.cpp.s
.PHONY : main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... GameProject2"
	@echo "... Entities/player.o"
	@echo "... Entities/player.i"
	@echo "... Entities/player.s"
	@echo "... Tools/savedata.o"
	@echo "... Tools/savedata.i"
	@echo "... Tools/savedata.s"
	@echo "... Tools/utils.o"
	@echo "... Tools/utils.i"
	@echo "... Tools/utils.s"
	@echo "... UI/alert.o"
	@echo "... UI/alert.i"
	@echo "... UI/alert.s"
	@echo "... UI/dialog.o"
	@echo "... UI/dialog.i"
	@echo "... UI/dialog.s"
	@echo "... UI/menu.o"
	@echo "... UI/menu.i"
	@echo "... UI/menu.s"
	@echo "... UI/message.o"
	@echo "... UI/message.i"
	@echo "... UI/message.s"
	@echo "... UI/puzzle.o"
	@echo "... UI/puzzle.i"
	@echo "... UI/puzzle.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
