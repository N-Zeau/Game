# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Users\Peultier Enzo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.7571.171\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Users\Peultier Enzo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\223.7571.171\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Peultier Enzo\CLionProjects\Game"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Peultier Enzo\CLionProjects\Game\cmake-build-debug"

# Include any dependencies generated for this target.
include src/CMakeFiles/AimBoost.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/AimBoost.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/AimBoost.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/AimBoost.dir/flags.make

src/CMakeFiles/AimBoost.dir/Sources/game.cpp.obj: src/CMakeFiles/AimBoost.dir/flags.make
src/CMakeFiles/AimBoost.dir/Sources/game.cpp.obj: src/CMakeFiles/AimBoost.dir/includes_CXX.rsp
src/CMakeFiles/AimBoost.dir/Sources/game.cpp.obj: C:/Users/Peultier\ Enzo/CLionProjects/Game/src/Sources/game.cpp
src/CMakeFiles/AimBoost.dir/Sources/game.cpp.obj: src/CMakeFiles/AimBoost.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Peultier Enzo\CLionProjects\Game\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/AimBoost.dir/Sources/game.cpp.obj"
	cd /d C:\Users\PEULTI~1\CLIONP~1\Game\CMAKE-~1\src && C:\Users\PEULTI~1\AppData\Local\JETBRA~1\Toolbox\apps\CLion\ch-0\223757~1.171\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/AimBoost.dir/Sources/game.cpp.obj -MF CMakeFiles\AimBoost.dir\Sources\game.cpp.obj.d -o CMakeFiles\AimBoost.dir\Sources\game.cpp.obj -c "C:\Users\Peultier Enzo\CLionProjects\Game\src\Sources\game.cpp"

src/CMakeFiles/AimBoost.dir/Sources/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AimBoost.dir/Sources/game.cpp.i"
	cd /d C:\Users\PEULTI~1\CLIONP~1\Game\CMAKE-~1\src && C:\Users\PEULTI~1\AppData\Local\JETBRA~1\Toolbox\apps\CLion\ch-0\223757~1.171\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Peultier Enzo\CLionProjects\Game\src\Sources\game.cpp" > CMakeFiles\AimBoost.dir\Sources\game.cpp.i

src/CMakeFiles/AimBoost.dir/Sources/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AimBoost.dir/Sources/game.cpp.s"
	cd /d C:\Users\PEULTI~1\CLIONP~1\Game\CMAKE-~1\src && C:\Users\PEULTI~1\AppData\Local\JETBRA~1\Toolbox\apps\CLion\ch-0\223757~1.171\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Peultier Enzo\CLionProjects\Game\src\Sources\game.cpp" -o CMakeFiles\AimBoost.dir\Sources\game.cpp.s

src/CMakeFiles/AimBoost.dir/Sources/main.cpp.obj: src/CMakeFiles/AimBoost.dir/flags.make
src/CMakeFiles/AimBoost.dir/Sources/main.cpp.obj: src/CMakeFiles/AimBoost.dir/includes_CXX.rsp
src/CMakeFiles/AimBoost.dir/Sources/main.cpp.obj: C:/Users/Peultier\ Enzo/CLionProjects/Game/src/Sources/main.cpp
src/CMakeFiles/AimBoost.dir/Sources/main.cpp.obj: src/CMakeFiles/AimBoost.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Peultier Enzo\CLionProjects\Game\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/AimBoost.dir/Sources/main.cpp.obj"
	cd /d C:\Users\PEULTI~1\CLIONP~1\Game\CMAKE-~1\src && C:\Users\PEULTI~1\AppData\Local\JETBRA~1\Toolbox\apps\CLion\ch-0\223757~1.171\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/AimBoost.dir/Sources/main.cpp.obj -MF CMakeFiles\AimBoost.dir\Sources\main.cpp.obj.d -o CMakeFiles\AimBoost.dir\Sources\main.cpp.obj -c "C:\Users\Peultier Enzo\CLionProjects\Game\src\Sources\main.cpp"

src/CMakeFiles/AimBoost.dir/Sources/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AimBoost.dir/Sources/main.cpp.i"
	cd /d C:\Users\PEULTI~1\CLIONP~1\Game\CMAKE-~1\src && C:\Users\PEULTI~1\AppData\Local\JETBRA~1\Toolbox\apps\CLion\ch-0\223757~1.171\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Peultier Enzo\CLionProjects\Game\src\Sources\main.cpp" > CMakeFiles\AimBoost.dir\Sources\main.cpp.i

src/CMakeFiles/AimBoost.dir/Sources/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AimBoost.dir/Sources/main.cpp.s"
	cd /d C:\Users\PEULTI~1\CLIONP~1\Game\CMAKE-~1\src && C:\Users\PEULTI~1\AppData\Local\JETBRA~1\Toolbox\apps\CLion\ch-0\223757~1.171\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Peultier Enzo\CLionProjects\Game\src\Sources\main.cpp" -o CMakeFiles\AimBoost.dir\Sources\main.cpp.s

src/CMakeFiles/AimBoost.dir/Sources/map.cpp.obj: src/CMakeFiles/AimBoost.dir/flags.make
src/CMakeFiles/AimBoost.dir/Sources/map.cpp.obj: src/CMakeFiles/AimBoost.dir/includes_CXX.rsp
src/CMakeFiles/AimBoost.dir/Sources/map.cpp.obj: C:/Users/Peultier\ Enzo/CLionProjects/Game/src/Sources/map.cpp
src/CMakeFiles/AimBoost.dir/Sources/map.cpp.obj: src/CMakeFiles/AimBoost.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Peultier Enzo\CLionProjects\Game\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/AimBoost.dir/Sources/map.cpp.obj"
	cd /d C:\Users\PEULTI~1\CLIONP~1\Game\CMAKE-~1\src && C:\Users\PEULTI~1\AppData\Local\JETBRA~1\Toolbox\apps\CLion\ch-0\223757~1.171\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/AimBoost.dir/Sources/map.cpp.obj -MF CMakeFiles\AimBoost.dir\Sources\map.cpp.obj.d -o CMakeFiles\AimBoost.dir\Sources\map.cpp.obj -c "C:\Users\Peultier Enzo\CLionProjects\Game\src\Sources\map.cpp"

src/CMakeFiles/AimBoost.dir/Sources/map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AimBoost.dir/Sources/map.cpp.i"
	cd /d C:\Users\PEULTI~1\CLIONP~1\Game\CMAKE-~1\src && C:\Users\PEULTI~1\AppData\Local\JETBRA~1\Toolbox\apps\CLion\ch-0\223757~1.171\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Peultier Enzo\CLionProjects\Game\src\Sources\map.cpp" > CMakeFiles\AimBoost.dir\Sources\map.cpp.i

src/CMakeFiles/AimBoost.dir/Sources/map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AimBoost.dir/Sources/map.cpp.s"
	cd /d C:\Users\PEULTI~1\CLIONP~1\Game\CMAKE-~1\src && C:\Users\PEULTI~1\AppData\Local\JETBRA~1\Toolbox\apps\CLion\ch-0\223757~1.171\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Peultier Enzo\CLionProjects\Game\src\Sources\map.cpp" -o CMakeFiles\AimBoost.dir\Sources\map.cpp.s

src/CMakeFiles/AimBoost.dir/Sources/player.cpp.obj: src/CMakeFiles/AimBoost.dir/flags.make
src/CMakeFiles/AimBoost.dir/Sources/player.cpp.obj: src/CMakeFiles/AimBoost.dir/includes_CXX.rsp
src/CMakeFiles/AimBoost.dir/Sources/player.cpp.obj: C:/Users/Peultier\ Enzo/CLionProjects/Game/src/Sources/player.cpp
src/CMakeFiles/AimBoost.dir/Sources/player.cpp.obj: src/CMakeFiles/AimBoost.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Peultier Enzo\CLionProjects\Game\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/AimBoost.dir/Sources/player.cpp.obj"
	cd /d C:\Users\PEULTI~1\CLIONP~1\Game\CMAKE-~1\src && C:\Users\PEULTI~1\AppData\Local\JETBRA~1\Toolbox\apps\CLion\ch-0\223757~1.171\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/AimBoost.dir/Sources/player.cpp.obj -MF CMakeFiles\AimBoost.dir\Sources\player.cpp.obj.d -o CMakeFiles\AimBoost.dir\Sources\player.cpp.obj -c "C:\Users\Peultier Enzo\CLionProjects\Game\src\Sources\player.cpp"

src/CMakeFiles/AimBoost.dir/Sources/player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AimBoost.dir/Sources/player.cpp.i"
	cd /d C:\Users\PEULTI~1\CLIONP~1\Game\CMAKE-~1\src && C:\Users\PEULTI~1\AppData\Local\JETBRA~1\Toolbox\apps\CLion\ch-0\223757~1.171\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Peultier Enzo\CLionProjects\Game\src\Sources\player.cpp" > CMakeFiles\AimBoost.dir\Sources\player.cpp.i

src/CMakeFiles/AimBoost.dir/Sources/player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AimBoost.dir/Sources/player.cpp.s"
	cd /d C:\Users\PEULTI~1\CLIONP~1\Game\CMAKE-~1\src && C:\Users\PEULTI~1\AppData\Local\JETBRA~1\Toolbox\apps\CLion\ch-0\223757~1.171\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Peultier Enzo\CLionProjects\Game\src\Sources\player.cpp" -o CMakeFiles\AimBoost.dir\Sources\player.cpp.s

# Object files for target AimBoost
AimBoost_OBJECTS = \
"CMakeFiles/AimBoost.dir/Sources/game.cpp.obj" \
"CMakeFiles/AimBoost.dir/Sources/main.cpp.obj" \
"CMakeFiles/AimBoost.dir/Sources/map.cpp.obj" \
"CMakeFiles/AimBoost.dir/Sources/player.cpp.obj"

# External object files for target AimBoost
AimBoost_EXTERNAL_OBJECTS =

C:/Users/Peultier\ Enzo/CLionProjects/Game/Ressources/Bin/AimBoost.exe: src/CMakeFiles/AimBoost.dir/Sources/game.cpp.obj
C:/Users/Peultier\ Enzo/CLionProjects/Game/Ressources/Bin/AimBoost.exe: src/CMakeFiles/AimBoost.dir/Sources/main.cpp.obj
C:/Users/Peultier\ Enzo/CLionProjects/Game/Ressources/Bin/AimBoost.exe: src/CMakeFiles/AimBoost.dir/Sources/map.cpp.obj
C:/Users/Peultier\ Enzo/CLionProjects/Game/Ressources/Bin/AimBoost.exe: src/CMakeFiles/AimBoost.dir/Sources/player.cpp.obj
C:/Users/Peultier\ Enzo/CLionProjects/Game/Ressources/Bin/AimBoost.exe: src/CMakeFiles/AimBoost.dir/build.make
C:/Users/Peultier\ Enzo/CLionProjects/Game/Ressources/Bin/AimBoost.exe: src/CMakeFiles/AimBoost.dir/linklibs.rsp
C:/Users/Peultier\ Enzo/CLionProjects/Game/Ressources/Bin/AimBoost.exe: src/CMakeFiles/AimBoost.dir/objects1.rsp
C:/Users/Peultier\ Enzo/CLionProjects/Game/Ressources/Bin/AimBoost.exe: src/CMakeFiles/AimBoost.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Peultier Enzo\CLionProjects\Game\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable \"C:\Users\Peultier Enzo\CLionProjects\Game\Ressources\Bin\AimBoost.exe\""
	cd /d C:\Users\PEULTI~1\CLIONP~1\Game\CMAKE-~1\src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\AimBoost.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/AimBoost.dir/build: C:/Users/Peultier\ Enzo/CLionProjects/Game/Ressources/Bin/AimBoost.exe
.PHONY : src/CMakeFiles/AimBoost.dir/build

src/CMakeFiles/AimBoost.dir/clean:
	cd /d C:\Users\PEULTI~1\CLIONP~1\Game\CMAKE-~1\src && $(CMAKE_COMMAND) -P CMakeFiles\AimBoost.dir\cmake_clean.cmake
.PHONY : src/CMakeFiles/AimBoost.dir/clean

src/CMakeFiles/AimBoost.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Peultier Enzo\CLionProjects\Game" "C:\Users\Peultier Enzo\CLionProjects\Game\src" "C:\Users\Peultier Enzo\CLionProjects\Game\cmake-build-debug" "C:\Users\Peultier Enzo\CLionProjects\Game\cmake-build-debug\src" "C:\Users\Peultier Enzo\CLionProjects\Game\cmake-build-debug\src\CMakeFiles\AimBoost.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : src/CMakeFiles/AimBoost.dir/depend

