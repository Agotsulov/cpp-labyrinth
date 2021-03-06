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
CMAKE_COMMAND = /home/byzilio/Programs/clion-2018.1.5/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/byzilio/Programs/clion-2018.1.5/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/byzilio/Workspace/Cpp/agotsulov-game/labyrinth

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/byzilio/Workspace/Cpp/agotsulov-game/labyrinth/cmake-build-debug

# Utility rule file for lint.

# Include the progress variables for this target.
include CMakeFiles/lint.dir/progress.make

CMakeFiles/lint: ../include/Actor.h
CMakeFiles/lint: ../include/Corp.h
CMakeFiles/lint: ../include/Engine.h
CMakeFiles/lint: ../include/GameObject.h
CMakeFiles/lint: ../include/ILevel.h
CMakeFiles/lint: ../include/VectorLevel.h
CMakeFiles/lint: ../include/actors/Block.h
CMakeFiles/lint: ../include/actors/Choose.h
CMakeFiles/lint: ../include/actors/Coin.h
CMakeFiles/lint: ../include/actors/CoinGenerator.h
CMakeFiles/lint: ../include/actors/Door.h
CMakeFiles/lint: ../include/actors/Floor.h
CMakeFiles/lint: ../include/actors/LeaderBoard.h
CMakeFiles/lint: ../include/actors/RealtimePlayer.h
CMakeFiles/lint: ../include/actors/RoguelikePlayer.h
CMakeFiles/lint: ../include/actors/Text.h
CMakeFiles/lint: ../src/Engine.cpp
CMakeFiles/lint: ../src/VectorLevel.cpp
CMakeFiles/lint: ../src/actors/Block.cpp
CMakeFiles/lint: ../src/actors/Choose.cpp
CMakeFiles/lint: ../src/actors/Coin.cpp
CMakeFiles/lint: ../src/actors/CoinGenerator.cpp
CMakeFiles/lint: ../src/actors/Door.cpp
CMakeFiles/lint: ../src/actors/Floor.cpp
CMakeFiles/lint: ../src/actors/LeaderBoard.cpp
CMakeFiles/lint: ../src/actors/RealtimePlayer.cpp
CMakeFiles/lint: ../src/actors/RoguelikePlayer.cpp
CMakeFiles/lint: ../src/actors/Text.cpp
CMakeFiles/lint: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/byzilio/Workspace/Cpp/agotsulov-game/labyrinth/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Linting lint"
	/home/byzilio/Programs/clion-2018.1.5/bin/cmake/bin/cmake -E chdir /home/byzilio/Workspace/Cpp/agotsulov-game/labyrinth /usr/bin/python /home/byzilio/Workspace/Cpp/agotsulov-game/labyrinth/misc/cpplint/cpplint.py --filter=-whitespace/ending_newline,-build/include_order,-build/namespaces,-build/include_what_you_use,-build/header_guard,-readability/streams,-readability/todo,-readability/namespace,-runtime/references,-legal/copyright, --counting=detailed --linelength=120 /home/byzilio/Workspace/Cpp/agotsulov-game/labyrinth/include/Actor.h /home/byzilio/Workspace/Cpp/agotsulov-game/labyrinth/include/Corp.h /home/byzilio/Workspace/Cpp/agotsulov-game/labyrinth/include/Engine.h /home/byzilio/Workspace/Cpp/agotsulov-game/labyrinth/include/GameObject.h /home/byzilio/Workspace/Cpp/agotsulov-game/labyrinth/include/ILevel.h /home/byzilio/Workspace/Cpp/agotsulov-game/labyrinth/include/VectorLevel.h /home/byzilio/Workspace/Cpp/agotsulov-game/labyrinth/include/actors/Block.h /home/byzilio/Workspace/Cpp/agotsulov-game/labyrinth/include/actors/Choose.h /home/byzilio/Workspace/Cpp/agotsulov-game/labyrinth/include/actors/Coin.h /home/byzilio/Workspace/Cpp/agotsulov-game/labyrinth/include/actors/CoinGenerator.h /home/byzilio/Workspace/Cpp/agotsulov-game/labyrinth/include/actors/Door.h /home/byzilio/Workspace/Cpp/agotsulov-game/labyrinth/include/actors/Floor.h /home/byzilio/Workspace/Cpp/agotsulov-game/labyrinth/include/actors/LeaderBoard.h /home/byzilio/Workspace/Cpp/agotsulov-game/labyrinth/include/actors/RealtimePlayer.h /home/byzilio/Workspace/Cpp/agotsulov-game/labyrinth/include/actors/RoguelikePlayer.h /home/byzilio/Workspace/Cpp/agotsulov-game/labyrinth/include/actors/Text.h /home/byzilio/Workspace/Cpp/agotsulov-game/labyrinth/src/Engine.cpp /home/byzilio/Workspace/Cpp/agotsulov-game/labyrinth/src/VectorLevel.cpp /home/byzilio/Workspace/Cpp/agotsulov-game/labyrinth/src/actors/Block.cpp /home/byzilio/Workspace/Cpp/agotsulov-game/labyrinth/src/actors/Choose.cpp /home/byzilio/Workspace/Cpp/agotsulov-game/labyrinth/src/actors/Coin.cpp /home/byzilio/Workspace/Cpp/agotsulov-game/labyrinth/src/actors/CoinGenerator.cpp /home/byzilio/Workspace/Cpp/agotsulov-game/labyrinth/src/actors/Door.cpp /home/byzilio/Workspace/Cpp/agotsulov-game/labyrinth/src/actors/Floor.cpp /home/byzilio/Workspace/Cpp/agotsulov-game/labyrinth/src/actors/LeaderBoard.cpp /home/byzilio/Workspace/Cpp/agotsulov-game/labyrinth/src/actors/RealtimePlayer.cpp /home/byzilio/Workspace/Cpp/agotsulov-game/labyrinth/src/actors/RoguelikePlayer.cpp /home/byzilio/Workspace/Cpp/agotsulov-game/labyrinth/src/actors/Text.cpp /home/byzilio/Workspace/Cpp/agotsulov-game/labyrinth/src/main.cpp

lint: CMakeFiles/lint
lint: CMakeFiles/lint.dir/build.make

.PHONY : lint

# Rule to build all files generated by this target.
CMakeFiles/lint.dir/build: lint

.PHONY : CMakeFiles/lint.dir/build

CMakeFiles/lint.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lint.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lint.dir/clean

CMakeFiles/lint.dir/depend:
	cd /home/byzilio/Workspace/Cpp/agotsulov-game/labyrinth/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/byzilio/Workspace/Cpp/agotsulov-game/labyrinth /home/byzilio/Workspace/Cpp/agotsulov-game/labyrinth /home/byzilio/Workspace/Cpp/agotsulov-game/labyrinth/cmake-build-debug /home/byzilio/Workspace/Cpp/agotsulov-game/labyrinth/cmake-build-debug /home/byzilio/Workspace/Cpp/agotsulov-game/labyrinth/cmake-build-debug/CMakeFiles/lint.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lint.dir/depend

