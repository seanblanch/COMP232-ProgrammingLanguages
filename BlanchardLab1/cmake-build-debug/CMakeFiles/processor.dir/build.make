# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.3.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.3.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\sean1\Desktop\Lab1_10

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\sean1\Desktop\Lab1_10\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/processor.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/processor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/processor.dir/flags.make

CMakeFiles/processor.dir/src/processor.c.obj: CMakeFiles/processor.dir/flags.make
CMakeFiles/processor.dir/src/processor.c.obj: CMakeFiles/processor.dir/includes_C.rsp
CMakeFiles/processor.dir/src/processor.c.obj: ../src/processor.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\sean1\Desktop\Lab1_10\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/processor.dir/src/processor.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\processor.dir\src\processor.c.obj   -c C:\Users\sean1\Desktop\Lab1_10\src\processor.c

CMakeFiles/processor.dir/src/processor.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/processor.dir/src/processor.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\sean1\Desktop\Lab1_10\src\processor.c > CMakeFiles\processor.dir\src\processor.c.i

CMakeFiles/processor.dir/src/processor.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/processor.dir/src/processor.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\sean1\Desktop\Lab1_10\src\processor.c -o CMakeFiles\processor.dir\src\processor.c.s

CMakeFiles/processor.dir/src/processor_test.c.obj: CMakeFiles/processor.dir/flags.make
CMakeFiles/processor.dir/src/processor_test.c.obj: CMakeFiles/processor.dir/includes_C.rsp
CMakeFiles/processor.dir/src/processor_test.c.obj: ../src/processor_test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\sean1\Desktop\Lab1_10\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/processor.dir/src/processor_test.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\processor.dir\src\processor_test.c.obj   -c C:\Users\sean1\Desktop\Lab1_10\src\processor_test.c

CMakeFiles/processor.dir/src/processor_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/processor.dir/src/processor_test.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\sean1\Desktop\Lab1_10\src\processor_test.c > CMakeFiles\processor.dir\src\processor_test.c.i

CMakeFiles/processor.dir/src/processor_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/processor.dir/src/processor_test.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\sean1\Desktop\Lab1_10\src\processor_test.c -o CMakeFiles\processor.dir\src\processor_test.c.s

# Object files for target processor
processor_OBJECTS = \
"CMakeFiles/processor.dir/src/processor.c.obj" \
"CMakeFiles/processor.dir/src/processor_test.c.obj"

# External object files for target processor
processor_EXTERNAL_OBJECTS =

processor.exe: CMakeFiles/processor.dir/src/processor.c.obj
processor.exe: CMakeFiles/processor.dir/src/processor_test.c.obj
processor.exe: CMakeFiles/processor.dir/build.make
processor.exe: CMakeFiles/processor.dir/linklibs.rsp
processor.exe: CMakeFiles/processor.dir/objects1.rsp
processor.exe: CMakeFiles/processor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\sean1\Desktop\Lab1_10\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable processor.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\processor.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/processor.dir/build: processor.exe

.PHONY : CMakeFiles/processor.dir/build

CMakeFiles/processor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\processor.dir\cmake_clean.cmake
.PHONY : CMakeFiles/processor.dir/clean

CMakeFiles/processor.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\sean1\Desktop\Lab1_10 C:\Users\sean1\Desktop\Lab1_10 C:\Users\sean1\Desktop\Lab1_10\cmake-build-debug C:\Users\sean1\Desktop\Lab1_10\cmake-build-debug C:\Users\sean1\Desktop\Lab1_10\cmake-build-debug\CMakeFiles\processor.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/processor.dir/depend

