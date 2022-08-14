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

Engine/gameobject.o: Engine/gameobject.cpp.o
.PHONY : Engine/gameobject.o

# target to build an object file
Engine/gameobject.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Engine/gameobject.cpp.o
.PHONY : Engine/gameobject.cpp.o

Engine/gameobject.i: Engine/gameobject.cpp.i
.PHONY : Engine/gameobject.i

# target to preprocess a source file
Engine/gameobject.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Engine/gameobject.cpp.i
.PHONY : Engine/gameobject.cpp.i

Engine/gameobject.s: Engine/gameobject.cpp.s
.PHONY : Engine/gameobject.s

# target to generate assembly for a file
Engine/gameobject.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Engine/gameobject.cpp.s
.PHONY : Engine/gameobject.cpp.s

Engine/main.o: Engine/main.cpp.o
.PHONY : Engine/main.o

# target to build an object file
Engine/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Engine/main.cpp.o
.PHONY : Engine/main.cpp.o

Engine/main.i: Engine/main.cpp.i
.PHONY : Engine/main.i

# target to preprocess a source file
Engine/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Engine/main.cpp.i
.PHONY : Engine/main.cpp.i

Engine/main.s: Engine/main.cpp.s
.PHONY : Engine/main.s

# target to generate assembly for a file
Engine/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Engine/main.cpp.s
.PHONY : Engine/main.cpp.s

Engine/map.o: Engine/map.cpp.o
.PHONY : Engine/map.o

# target to build an object file
Engine/map.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Engine/map.cpp.o
.PHONY : Engine/map.cpp.o

Engine/map.i: Engine/map.cpp.i
.PHONY : Engine/map.i

# target to preprocess a source file
Engine/map.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Engine/map.cpp.i
.PHONY : Engine/map.cpp.i

Engine/map.s: Engine/map.cpp.s
.PHONY : Engine/map.s

# target to generate assembly for a file
Engine/map.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Engine/map.cpp.s
.PHONY : Engine/map.cpp.s

Engine/minimap.o: Engine/minimap.cpp.o
.PHONY : Engine/minimap.o

# target to build an object file
Engine/minimap.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Engine/minimap.cpp.o
.PHONY : Engine/minimap.cpp.o

Engine/minimap.i: Engine/minimap.cpp.i
.PHONY : Engine/minimap.i

# target to preprocess a source file
Engine/minimap.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Engine/minimap.cpp.i
.PHONY : Engine/minimap.cpp.i

Engine/minimap.s: Engine/minimap.cpp.s
.PHONY : Engine/minimap.s

# target to generate assembly for a file
Engine/minimap.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Engine/minimap.cpp.s
.PHONY : Engine/minimap.cpp.s

Engine/room.o: Engine/room.cpp.o
.PHONY : Engine/room.o

# target to build an object file
Engine/room.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Engine/room.cpp.o
.PHONY : Engine/room.cpp.o

Engine/room.i: Engine/room.cpp.i
.PHONY : Engine/room.i

# target to preprocess a source file
Engine/room.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Engine/room.cpp.i
.PHONY : Engine/room.cpp.i

Engine/room.s: Engine/room.cpp.s
.PHONY : Engine/room.s

# target to generate assembly for a file
Engine/room.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Engine/room.cpp.s
.PHONY : Engine/room.cpp.s

Entities/artifact.o: Entities/artifact.cpp.o
.PHONY : Entities/artifact.o

# target to build an object file
Entities/artifact.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Entities/artifact.cpp.o
.PHONY : Entities/artifact.cpp.o

Entities/artifact.i: Entities/artifact.cpp.i
.PHONY : Entities/artifact.i

# target to preprocess a source file
Entities/artifact.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Entities/artifact.cpp.i
.PHONY : Entities/artifact.cpp.i

Entities/artifact.s: Entities/artifact.cpp.s
.PHONY : Entities/artifact.s

# target to generate assembly for a file
Entities/artifact.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Entities/artifact.cpp.s
.PHONY : Entities/artifact.cpp.s

Entities/bullet.o: Entities/bullet.cpp.o
.PHONY : Entities/bullet.o

# target to build an object file
Entities/bullet.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Entities/bullet.cpp.o
.PHONY : Entities/bullet.cpp.o

Entities/bullet.i: Entities/bullet.cpp.i
.PHONY : Entities/bullet.i

# target to preprocess a source file
Entities/bullet.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Entities/bullet.cpp.i
.PHONY : Entities/bullet.cpp.i

Entities/bullet.s: Entities/bullet.cpp.s
.PHONY : Entities/bullet.s

# target to generate assembly for a file
Entities/bullet.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Entities/bullet.cpp.s
.PHONY : Entities/bullet.cpp.s

Entities/entity.o: Entities/entity.cpp.o
.PHONY : Entities/entity.o

# target to build an object file
Entities/entity.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Entities/entity.cpp.o
.PHONY : Entities/entity.cpp.o

Entities/entity.i: Entities/entity.cpp.i
.PHONY : Entities/entity.i

# target to preprocess a source file
Entities/entity.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Entities/entity.cpp.i
.PHONY : Entities/entity.cpp.i

Entities/entity.s: Entities/entity.cpp.s
.PHONY : Entities/entity.s

# target to generate assembly for a file
Entities/entity.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Entities/entity.cpp.s
.PHONY : Entities/entity.cpp.s

Entities/foe.o: Entities/foe.cpp.o
.PHONY : Entities/foe.o

# target to build an object file
Entities/foe.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Entities/foe.cpp.o
.PHONY : Entities/foe.cpp.o

Entities/foe.i: Entities/foe.cpp.i
.PHONY : Entities/foe.i

# target to preprocess a source file
Entities/foe.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Entities/foe.cpp.i
.PHONY : Entities/foe.cpp.i

Entities/foe.s: Entities/foe.cpp.s
.PHONY : Entities/foe.s

# target to generate assembly for a file
Entities/foe.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Entities/foe.cpp.s
.PHONY : Entities/foe.cpp.s

Entities/food.o: Entities/food.cpp.o
.PHONY : Entities/food.o

# target to build an object file
Entities/food.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Entities/food.cpp.o
.PHONY : Entities/food.cpp.o

Entities/food.i: Entities/food.cpp.i
.PHONY : Entities/food.i

# target to preprocess a source file
Entities/food.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Entities/food.cpp.i
.PHONY : Entities/food.cpp.i

Entities/food.s: Entities/food.cpp.s
.PHONY : Entities/food.s

# target to generate assembly for a file
Entities/food.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Entities/food.cpp.s
.PHONY : Entities/food.cpp.s

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

Entities/vendor.o: Entities/vendor.cpp.o
.PHONY : Entities/vendor.o

# target to build an object file
Entities/vendor.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Entities/vendor.cpp.o
.PHONY : Entities/vendor.cpp.o

Entities/vendor.i: Entities/vendor.cpp.i
.PHONY : Entities/vendor.i

# target to preprocess a source file
Entities/vendor.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Entities/vendor.cpp.i
.PHONY : Entities/vendor.cpp.i

Entities/vendor.s: Entities/vendor.cpp.s
.PHONY : Entities/vendor.s

# target to generate assembly for a file
Entities/vendor.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Entities/vendor.cpp.s
.PHONY : Entities/vendor.cpp.s

Entities/weapon.o: Entities/weapon.cpp.o
.PHONY : Entities/weapon.o

# target to build an object file
Entities/weapon.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Entities/weapon.cpp.o
.PHONY : Entities/weapon.cpp.o

Entities/weapon.i: Entities/weapon.cpp.i
.PHONY : Entities/weapon.i

# target to preprocess a source file
Entities/weapon.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Entities/weapon.cpp.i
.PHONY : Entities/weapon.cpp.i

Entities/weapon.s: Entities/weapon.cpp.s
.PHONY : Entities/weapon.s

# target to generate assembly for a file
Entities/weapon.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Entities/weapon.cpp.s
.PHONY : Entities/weapon.cpp.s

Tools/GameObjectList.o: Tools/GameObjectList.cpp.o
.PHONY : Tools/GameObjectList.o

# target to build an object file
Tools/GameObjectList.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Tools/GameObjectList.cpp.o
.PHONY : Tools/GameObjectList.cpp.o

Tools/GameObjectList.i: Tools/GameObjectList.cpp.i
.PHONY : Tools/GameObjectList.i

# target to preprocess a source file
Tools/GameObjectList.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Tools/GameObjectList.cpp.i
.PHONY : Tools/GameObjectList.cpp.i

Tools/GameObjectList.s: Tools/GameObjectList.cpp.s
.PHONY : Tools/GameObjectList.s

# target to generate assembly for a file
Tools/GameObjectList.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/Tools/GameObjectList.cpp.s
.PHONY : Tools/GameObjectList.cpp.s

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

UI/inventory.o: UI/inventory.cpp.o
.PHONY : UI/inventory.o

# target to build an object file
UI/inventory.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/UI/inventory.cpp.o
.PHONY : UI/inventory.cpp.o

UI/inventory.i: UI/inventory.cpp.i
.PHONY : UI/inventory.i

# target to preprocess a source file
UI/inventory.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/UI/inventory.cpp.i
.PHONY : UI/inventory.cpp.i

UI/inventory.s: UI/inventory.cpp.s
.PHONY : UI/inventory.s

# target to generate assembly for a file
UI/inventory.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/UI/inventory.cpp.s
.PHONY : UI/inventory.cpp.s

UI/itemselector.o: UI/itemselector.cpp.o
.PHONY : UI/itemselector.o

# target to build an object file
UI/itemselector.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/UI/itemselector.cpp.o
.PHONY : UI/itemselector.cpp.o

UI/itemselector.i: UI/itemselector.cpp.i
.PHONY : UI/itemselector.i

# target to preprocess a source file
UI/itemselector.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/UI/itemselector.cpp.i
.PHONY : UI/itemselector.cpp.i

UI/itemselector.s: UI/itemselector.cpp.s
.PHONY : UI/itemselector.s

# target to generate assembly for a file
UI/itemselector.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/UI/itemselector.cpp.s
.PHONY : UI/itemselector.cpp.s

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

UI/shop.o: UI/shop.cpp.o
.PHONY : UI/shop.o

# target to build an object file
UI/shop.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/UI/shop.cpp.o
.PHONY : UI/shop.cpp.o

UI/shop.i: UI/shop.cpp.i
.PHONY : UI/shop.i

# target to preprocess a source file
UI/shop.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/UI/shop.cpp.i
.PHONY : UI/shop.cpp.i

UI/shop.s: UI/shop.cpp.s
.PHONY : UI/shop.s

# target to generate assembly for a file
UI/shop.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/UI/shop.cpp.s
.PHONY : UI/shop.cpp.s

UI/stats.o: UI/stats.cpp.o
.PHONY : UI/stats.o

# target to build an object file
UI/stats.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/UI/stats.cpp.o
.PHONY : UI/stats.cpp.o

UI/stats.i: UI/stats.cpp.i
.PHONY : UI/stats.i

# target to preprocess a source file
UI/stats.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/UI/stats.cpp.i
.PHONY : UI/stats.cpp.i

UI/stats.s: UI/stats.cpp.s
.PHONY : UI/stats.s

# target to generate assembly for a file
UI/stats.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/GameProject2.dir/build.make CMakeFiles/GameProject2.dir/UI/stats.cpp.s
.PHONY : UI/stats.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... GameProject2"
	@echo "... Engine/gameobject.o"
	@echo "... Engine/gameobject.i"
	@echo "... Engine/gameobject.s"
	@echo "... Engine/main.o"
	@echo "... Engine/main.i"
	@echo "... Engine/main.s"
	@echo "... Engine/map.o"
	@echo "... Engine/map.i"
	@echo "... Engine/map.s"
	@echo "... Engine/minimap.o"
	@echo "... Engine/minimap.i"
	@echo "... Engine/minimap.s"
	@echo "... Engine/room.o"
	@echo "... Engine/room.i"
	@echo "... Engine/room.s"
	@echo "... Entities/artifact.o"
	@echo "... Entities/artifact.i"
	@echo "... Entities/artifact.s"
	@echo "... Entities/bullet.o"
	@echo "... Entities/bullet.i"
	@echo "... Entities/bullet.s"
	@echo "... Entities/entity.o"
	@echo "... Entities/entity.i"
	@echo "... Entities/entity.s"
	@echo "... Entities/foe.o"
	@echo "... Entities/foe.i"
	@echo "... Entities/foe.s"
	@echo "... Entities/food.o"
	@echo "... Entities/food.i"
	@echo "... Entities/food.s"
	@echo "... Entities/player.o"
	@echo "... Entities/player.i"
	@echo "... Entities/player.s"
	@echo "... Entities/vendor.o"
	@echo "... Entities/vendor.i"
	@echo "... Entities/vendor.s"
	@echo "... Entities/weapon.o"
	@echo "... Entities/weapon.i"
	@echo "... Entities/weapon.s"
	@echo "... Tools/GameObjectList.o"
	@echo "... Tools/GameObjectList.i"
	@echo "... Tools/GameObjectList.s"
	@echo "... Tools/savedata.o"
	@echo "... Tools/savedata.i"
	@echo "... Tools/savedata.s"
	@echo "... Tools/utils.o"
	@echo "... Tools/utils.i"
	@echo "... Tools/utils.s"
	@echo "... UI/dialog.o"
	@echo "... UI/dialog.i"
	@echo "... UI/dialog.s"
	@echo "... UI/inventory.o"
	@echo "... UI/inventory.i"
	@echo "... UI/inventory.s"
	@echo "... UI/itemselector.o"
	@echo "... UI/itemselector.i"
	@echo "... UI/itemselector.s"
	@echo "... UI/message.o"
	@echo "... UI/message.i"
	@echo "... UI/message.s"
	@echo "... UI/shop.o"
	@echo "... UI/shop.i"
	@echo "... UI/shop.s"
	@echo "... UI/stats.o"
	@echo "... UI/stats.i"
	@echo "... UI/stats.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

